#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],sum=0;
void dfs(int k,int p,int u){
	if(k>n){
		return;
	}
	if(k>=3){
		if(u>a[p]*2){
			sum+=1;
			sum%=998244353;
			//cout<<k<<" "<<p<<" "<<u<<endl;
		}
	}
	k+=1;
	for(int i=p+1;i<=n;i++){
		dfs(k,i,u+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		int o=max(max(a[1],a[2]),a[3]);
		int o1=a[1]+a[2]+a[3];
		if(o1>o*2){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	sort(a+1,a+1+n);
	dfs(0,0,0);
	sum%=998244353;
	cout<<sum;
	return 0;
}



