#include<bits/stdc++.h>
using namespace std;
const int L=3e6+5,N=2e5+5;
char a[L],b[L];
bool Tihuan(){
	int l=1,r=0,len=strlen(a+1);
	for(int i=1; i<=len; i++)if(a[i]!=b[i]){l=i;break;}
	for(int i=len; i>=1; i--)if(a[i]!=b[i]){r=i;break;}
	if(r<l)return 1;
	for(int i=1,j=l; i<=len; i++,j++){
		if(j<=r)a[i]=a[j],b[i]=b[j];
		else a[i]=b[i]=a[0];
	}
	return 0;
}
map<string,int>ma,pd;
map<int,int>js[N<<1],tj[N<<1];
char c[L],d[L];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,T;cin>>n>>T;
	int bj=0,jl=0;
	for(int i=1,d1,d2; i<=n; i++){
		scanf("%s%s",a+1,b+1);
		for(int i=1; i<=strlen(a+1); i++)c[i]=a[i],d[i]=b[i];
		if(!pd.count(a+1))pd[a+1]=++jl,d1=jl;
		else d1=pd[a+1];
		if(!pd.count(b+1))pd[b+1]=++jl,d2=jl;
		else d2=pd[b+1];
//		if(tj[d1].count(d2))continue;
		tj[d1][d2]++;
		if(Tihuan())continue;
		if(!ma.count(a+1))ma[a+1]=++bj,d1=bj;
		else d1=ma[a+1];
		if(!ma.count(b+1))ma[b+1]=++bj,d2=bj;
		else d2=ma[b+1];
		js[d1][d2]++;
//		if(a[1]=='m'&&b[1]=='d'&&strlen(a+1)==1)cout<<c+1<<" "<<d+1<<"\n";
	}
	while(T--){
		scanf("%s%s",a+1,b+1);
		if(strlen(a+1)!=strlen(b+1)){printf("0\n");continue;}
		Tihuan();
		int d1,d2;
		if(!ma.count(a+1)){printf("0\n");continue;}
		else d1=ma[a+1];
		if(!ma.count(b+1)){printf("0\n");continue;}
		else d2=ma[b+1];
		printf("%d\n",js[d1][d2]);
	}
	return 0;
}
