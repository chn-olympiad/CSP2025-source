#include <iostream>
#include <cstdio>
#include <algorithm>
#define pii pair<int,int>
#define fi first
#define se second 
using namespace std;

int n,k;
int a[500005];
int bin[500005][25];
namespace sub1{
	int sum[500005];
	pii p[500005];
	int cnt=0;
	int ans=0;
	int f[500005];
	bool cmp(pii x,pii y){
		int lenx=x.se-x.fi+1;
		int leny=y.se-y.fi+1;
//		if(lenx==leny)
//			return x.fi<y.fi;
		return lenx<leny;
	}
	void sol(){
//		cout<<k<<endl;
		for(int i=1;i<=n;i++)
			sum[i]=sum[i-1]^a[i];
//		cout<<(((142)^57)^183)<<endl;
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				if((sum[j]^sum[i-1])==k){
//					cout<<i<<' '<<j<<' '<<(sum[j]^sum[i-1])<<endl; 
					p[++cnt]={i,j};
				}
		sort(p+1,p+cnt+1,cmp);
//		cout<<cnt<<endl;
//		cout<<p[30].fi<<' '<<p[30].se<<endl;
		do{
			for(int i=1;i<500005;i++)
				f[i]=0;
			int res=0;
			for(int i=1;i<=cnt;i++){
				int fl=0;
				for(int j=p[i].fi;j<=p[i].se;j++){
					if(f[j]){
						fl=1;
						break;
					}
				}
				if(fl)
					continue;
//				cout<<p[i].fi<<' '<<p[i].se<<' '<<i<<endl;
				for(int j=p[i].fi;j<=p[i].se;j++)
					f[j]=1;
				res++; 
			}
			ans=max(ans,res);
		}while(next_permutation(p+1,p+cnt+1));
		cout<<ans<<endl;
	}
}
namespace sub2{
	int sum[500005];
	pii p[500005];
	int cnt=0;
	int ans=0;
//	int f;
	int f[500005];
	bool cmp(pii x,pii y){
		int lenx=x.se-x.fi+1;
		int leny=y.se-y.fi+1;
//		if(lenx==leny)
//			return x.fi<y.fi;
		return lenx<leny;
	}
	void sol(){
//		cout<<k<<endl;
		for(int i=1;i<=n;i++)
			sum[i]=sum[i-1]^a[i];
//		cout<<(((142)^57)^183)<<endl;
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				if((sum[j]^sum[i-1])==k){
//					cout<<i<<' '<<j<<' '<<(sum[j]^sum[i-1])<<endl; 
					p[++cnt]={i,j};
				}
		sort(p+1,p+cnt+1,cmp);
//		cout<<cnt<<endl;
//		cout<<p[30].fi<<' '<<p[30].se<<endl;
		for(int i=1;i<=cnt;i++){
			int fl=0;
			for(int j=p[i].fi;j<=p[i].se;j++){
				if(f[j]){
					fl=1;
					break;
				}
			}
			if(fl)
				continue;
//			cout<<p[i].fi<<' '<<p[i].se<<' '<<i<<endl;
			for(int j=p[i].fi;j<=p[i].se;j++)
				f[j]=1;
			ans++; 
		}
		cout<<ans<<endl;
	}
}
namespace sub3{
	void sol(){
//		cout<<111;
		if(k==0){
			int ans=0;
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans++;
					ans+=(cnt/2);
					cnt=0; 
				}
			}
			cout<<ans<<endl;
		}
		else{
			int ans=0;
			for(int i=1;i<=n;i++)
				if(a[i]==1)
					ans++;
			cout<<ans<<endl;
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	int fl=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)
			fl=1;
	}
	int cnt=0;
	int k2=k;
	while(k2){
		if(k2%2==1)
			bin[0][++cnt]=1;
		k2>>=1;
	}
	for(int i=1;i<=n;i++){
		int x=a[i];
		cnt=0;
		while(x){
			if(x%2==1)
				bin[i][++cnt]=1;
			x>>=1; 
		}
	}
	if(n<=10)
		sub1::sol();
	else if(!fl)
		sub3::sol();
	else
		sub2::sol();
	return 0;
}
/*
4 2 
2 1 0 3
*/ 
