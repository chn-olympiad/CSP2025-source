#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=998244353;
int n,a[5010],ans=0;
signed vh[510][510][2010];
int f(int id,int k,int sum){
	if(k>n){
		return 0;
	}
	if(vh[id][k][sum]!=-1){
		return vh[id][k][sum];
	}
	if(id==1){
		if(sum>a[k]){
			return vh[id][k][sum]=1+f(id,k+1,sum)%M;
		}
		return vh[id][k][sum]=f(id,k+1,sum)%M;
	}
	return vh[id][k][sum]=(f(id,k+1,sum)+f(id-1,k+1,sum+a[k]))%M;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	memset(vh,-1,sizeof(vh));
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;++i){
		ans+=f(i,1,0);
	}
	cout<<ans%M<<endl;
	return 0;
}
