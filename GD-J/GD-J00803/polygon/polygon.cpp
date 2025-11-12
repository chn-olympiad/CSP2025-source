#include<bits/stdc++.h>
using namespace std;
const long long Mod=998244353;
int a[5005];
long long b[5005];
int n;
bool flag1=1,flag2=1;

void solve_1(){
	b[0]=1;
	for(int i=1;i<=n;i++){
		b[i]=(b[i-1]*i)%Mod;
	}long long ans=0;
	for(int i=3;i<=n;i++){
		ans+=(b[n]/b[i]/b[n-i])%Mod;
		ans%=Mod;
	}cout<<ans;
	return;
}
int mx,ans;
void dfs(int i,int sm){
	if(sm>mx){
		ans++;
	}if(i==0){
		return;
	}for(int j=1;j<=i;j++){
		dfs(j-1,sm+a[j]);
	}
}

void solve_2(){
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		mx=a[i];
		dfs(i-1,0);
	}cout<<ans;
	
	return;
} 


int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie();
	cout.tie();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1 and a[i]!=a[i-1]){
			flag1=0;
		}if(a[i]!=1){
			flag2=0;
		}
	}if(flag1 or flag2){
		solve_1();
	}else if(n==3){
		if(a[1]+a[2]>a[3] and a[2]+a[3]>a[1] and a[1]+a[3]>a[2]){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}else{
		solve_2();
	}
	
	
	
	return 0;
} 
