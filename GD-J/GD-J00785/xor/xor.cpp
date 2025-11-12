#include<bits/stdc++.h>
using namespace std;
int a[500005],sa[500005];
int id[500005],ids[500005];
int s[2][500005],lfids[500005];
vector<int> ff,fids;
int n,k,lk,ans;
bool cmp(int ax,int by){
	if(sa[ax]<sa[by]) return true;
	if(sa[ax]==sa[by]) return ax<by?true:false;
	return false;
}
int sea(int pn){
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2;
		if(sa[id[mid]]<pn) l=mid+1;
		else r=mid;
	}
	return l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(k){
		lk=log2(k);
		lk=1<<lk;
	}
	else lk=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>=lk) ff.push_back(i);
		sa[i]=sa[i-1]^a[i];
		id[i]=i;
	}
	sort(id+1,id+n+1,cmp);
	for(unsigned int i=0;i<ff.size();i++){
		if(a[ff[i]]==k){
			fids.push_back(ff[i]);
			ids[ff[i]]=ff[i];
			continue;
		}
		int fsa=sa[ff[i]]^k,fsb=sa[ff[i]-1]^k;
		int lposit=sea(fsa);
		int bposit=sea(fsb);
		if(sa[id[lposit]]==fsa){
			while(sa[id[lposit]]==sa[id[lposit+1]]&&id[lposit+1]<ff[i]) lposit++;
			if(id[lposit]<ff[i]){
				if(!ids[id[lposit]+1]){
					ids[id[lposit]+1]=id[ff[i]];
					fids.push_back(id[lposit]+1);
				}
				else ids[id[lposit]+1]=min(ids[id[lposit]+1],id[ff[i]]);
			}
		}
		if(sa[id[bposit]]!=fsb){
			while(sa[id[bposit]]==sa[id[bposit-1]]&&id[bposit-1]>ff[i]) bposit--;
			if(id[bposit]>ff[i]){
				if(!ids[ff[i]]){
					ids[ff[i]]=id[bposit];
					fids.push_back(ff[i]);
				}
				else ids[ff[i]]=min(ids[ff[i]],id[bposit]);
			}
		}
	}
	int fil=fids.size();
	for(int i=0;i<fil;i++) lfids[i]=fids[i];
	sort(lfids,lfids+fil);
	for(int i=0;i<fil;i++){
		for(int t=1;t<lfids[i];t++) s[1][t]=s[0][t];
		for(int t=i;t<fil;t++){
			s[1][lfids[t]]=s[0][lfids[t]-1]+1;
			for(int j=lfids[t]+1;t+1<fil&&j<lfids[t+1];j++) s[1][j]=s[1][j-1];
		}
		for(int t=1;t<=lfids[fil-1];t++) s[0][t]=s[1][t];
	}
	printf("%d",s[0][lfids[fil-1]]);
	return 0;
}
