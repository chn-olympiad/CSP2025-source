#include <bits/stdc++.h>
using namespace std;
int t,n,sum,ac,bc,cc,ma[100001],mb[100001],mc[100001];
bool cmp(int a,int b){
	return a>b;
}
void fp(){
	for(int i=1;i<=n;i++){
		int maxn=-1;
		if(ma[i]>maxn&&ac<n/2) maxn=ma[i];
		if(mb[i]>maxn&&bc<n/2) maxn=mb[i];
		if(mc[i]>maxn&&cc<n/2) maxn=mc[i];
		if(maxn==ma[i]&&ac<n/2) ac++;
		else if(ac=n/2){
			if(bc=n/2) maxn=mc[i];
			else if(cc=n/2) maxn=mb[i];
			else maxn=max(mb[i],mc[i]);
		}
		if(maxn==mb[i]&&bc<n/2) bc++;
		else if(bc=n/2){
			if(ac=n/2) maxn=mc[i];
			else if(cc=n/2) maxn=ma[i];
			else maxn=max(ma[i],mc[i]);
		}
		if(maxn==mc[i]&&cc<n/2) cc++;
		else if(cc==n/2){
			if(ac=n/2) maxn=mb[i];
			else if(bc=n/2) maxn=ma[i];
			else maxn=max(ma[i],mb[i]);
		}
		sum+=maxn;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>ma[i]>>mb[i]>>mc[i];
		sort(ma+1,ma+n+1,cmp);
		sort(mb+1,mb+n+1,cmp);
		sort(mc+1,mc+n+1,cmp);
		fp();
		cout<<sum<<endl;
		memset(ma,0,sizeof(ma));
		memset(mb,0,sizeof(mb));
		memset(mc,0,sizeof(mc));
		sum=ac=bc=cc=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
