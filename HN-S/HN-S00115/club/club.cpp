#include<bits/stdc++.h>
using namespace std;
const int MN=1e5+6;
long long n,ap[MN],bp[MN],cp[MN];
long long m,ma[MN],mb[MN],mc[MN];
long long as[MN]={},bs[MN]={},cs[MN]={};
long long ai,bi,ci,zn,zm;
struct node{
	long long a,b,c;
}cy[MN];
int jc(){
	if(ma[0]>n/2||mb[0]>n/2||mc[0]>n/2)
		return 1;
	return 0;
}
void fp(){
	if(ma[0]>n/2){
		ma[0]--;
		ai--;
		if(mb[0]==n/2||cy[bp[bi]].b<cy[cp[ci]].c){
			mc[++mc[0]]=cp[ci];
			ci++;
		}
		else{
			mb[++mb[0]]=bp[bi];
			bi++;
		}
	}
	if(mb[0]>n/2){
		mb[0]--;
		bi--;
		if(ma[0]==n/2||cy[ap[ai]].a<cy[cp[ci]].c){
			mc[++mc[0]]=cp[ci];
			ci++;
		}
		else{
			ma[++ma[0]]=ap[ai];
			ai++;
		}
	}
	if(mc[0]>n/2){
		mc[0]--;
		ci--;
		if(mb[0]==n/2||cy[bp[bi]].b<cy[ap[ai]].a){
			ma[++ma[0]]=ap[ai];
			ai++;
		}
		else{
			mb[++mb[0]]=bp[bi];
			bi++;
		}
	}
	for(int i=1;i<=n;i++){
		if(as[i]&&bs[i]){
			zn=cy[as[i]].a+cy[bp[bi]].b;
			zm=cy[bs[i]].b+cy[ap[ai]].a;
			if(zn>zm){
				mb[bs[i]]=bp[bi];
				bs[i]=0;
				bi++;
			}
			else{
				ma[as[i]]=ap[ai];
				as[i]=0;
				ai++;
			}
		}
		if(as[i]&&cs[i]){
			zn=cy[as[i]].a+cy[cp[ci]].c;
			zm=cy[cs[i]].b+cy[ap[ai]].a;
			if(zn>zm){
				mc[cs[i]]=cp[ci];
				cs[i]=0;
				ci++;
			}
			else{
				ma[as[i]]=ap[ai];
				as[i]=0;
				ai++;
			}
		}
		if(cs[i]&&bs[i]){
			zn=cy[cs[i]].c+cy[bp[bi]].b;
			zm=cy[bs[i]].b+cy[cp[ci]].c;
			if(zn>zm){
				mb[bs[i]]=bp[bi];
				bs[i]=0;
				bi++;
			}
			else{
				mc[cs[i]]=cp[ci];
				cs[i]=0;
				ci++;
			}
		}
	}
}
void fz(){
	if(cy[ap[ai]].a>=cy[bp[bi]].b&&cy[ap[ai]].a>=cy[cp[ci]].c){
		ma[++ma[0]]=ap[ai];
		as[ap[ai]]=ma[0];
		ai++;
	}
	else if(cy[bp[bi]].b>cy[ap[ai]].a&&cy[bp[bi]].b>=cy[cp[ci]].c){
		mb[++mb[0]]=bp[bi];
		bs[bp[bi]]=mb[0];
		bi++;
	}
	else{
		mc[++mc[0]]=cp[ci];
		cs[cp[ci]]=mc[0];
		ci++;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		m=ma[0]=mb[0]=mc[0]=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>cy[i].a>>cy[i].b>>cy[i].c;
		for(int i=1;i<=n;i++)
			ap[i]=bp[i]=cp[i]=i;
		for(int i=2;i<=n;i++)
			for(int j=n;j>=i;j--)
				if(cy[ap[j]].a>cy[ap[j-1]].a)
					swap(ap[j],ap[j-1]);
		for(int i=2;i<=n;i++)
			for(int j=n;j>=i;j--)
				if(cy[bp[j]].b>cy[bp[j-1]].b)
					swap(bp[j],bp[j-1]);
		for(int i=2;i<=n;i++)
			for(int j=n;j>=i;j--)
				if(cy[cp[j]].c>cy[cp[j-1]].c)
					swap(cp[j],cp[j-1]);
		ai=bi=ci=1;
		for(int i=1;i<=n;i++)
			fz();
		fp();
		while(jc()) fp();
		for(int i=1;i<=ma[0];i++)
			m+=cy[ma[i]].a;
		for(int i=1;i<=mb[0];i++)
			m+=cy[mb[i]].b;
		for(int i=1;i<=mc[0];i++)
			m+=cy[mc[i]].c;
		cout<<m<<endl;
	}
	return 0;
}
