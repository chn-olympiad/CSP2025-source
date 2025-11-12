#include<bits/stdc++.h>
using namespace std;
long long n,a[5001],ans;
long long M=998244353;
long long zai[5001],zhai[5001];
long long to[5001];
void dfs(int c,long long sum,long long Max,int shang){
	if(c>3){
		if(sum>2*Max){
			ans++;
			ans%=M;
		}
		if(c>n)
			return ; 
	}
	for(int i=shang+1;i<=n;i++){
		if(!to[i]){
			to[i]=1;
			dfs(c+1,sum+a[i],a[i],i);
			to[i]=0;
		} 
	}
}
long long da(int x,int y){
	if(x>y/2){
		x=y-x;
	}
	for(int i=1;i<=5000;i++)
		zai[i]=zhai[i]=0;
	for(int i=2;i<=x;i++){
		int ll=i;
		int z=2;
		while(ll!=1){
			while(ll%z==0){
				zai[z]++;
				ll/=z;
			}
			z++;
		}
	} 
	long long sum=1;
	for(int i=y;i>=y-x+1;i--){
		int ll=i;
		int z=2;
		while(ll!=1){
			while(ll%z==0){
				zhai[z]++;
				ll/=z;
			}
			z++;
		}
	}
	for(int i=2;i<=5000;i++){
		for(int j=1;j<=zhai[i]-zai[i];j++){
			sum*=i;
			sum%=M;
		}
	}
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	
	if(n<3){
		cout<<0;
		return 0;
	}
	if(a[n]==1){
		for(int i=3;i<=n;i++){
			ans+=da(i,n);
			ans%=M; 
		}
		cout<<ans;
		return 0;
	} 
	if(n==3){
		if( (a[1]+a[2]+a[3]) > (2*a[3]) ){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
