#include<bits/stdc++.h>
using namespace std;
int n,b[10000],ans=0;
vector<int>a; 
void sol(int n,int q,int z,int lev,vector<int>a){
	for(int i=q;i<=z;i++){
		a[lev-1]=i;
		if(lev!=n){
			sol(n,i+1,z,lev+1,a);
		}
		else{
			int maxn=0,sum=0;
			for(int j=0;j<lev;j++){
				sum+=b[a[j]]; maxn=max(b[a[j]],maxn);
			}
			if(sum>maxn*2) ans=(ans+1)%998244353;
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		a.push_back(0);
	}
	for(int h=3;h<=n;h++){
		sol(h,1,n,1,a);
	}
	cout<<ans%998244353;
	return 0;
}
