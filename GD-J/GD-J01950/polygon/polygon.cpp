#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e3+10,mod=998244353;
ll n,a[N],vis[N],s[N],nm[N];
void work1ss(){
	nm[0]=0;
	nm[1]=1;
	ll ans=1;
	for (int i=2;i<=5002;i++){
		nm[i]=(nm[i-1]*i)%mod;
	}
	for (int i=3;i<n;i++){
		ans=ans+(nm[n]/nm[i]/nm[n-i]+mod)%mod;
	}
	cout<<ans<<endl;
	return ;
}
void work2zxss(){
	nm[0]=0;
	nm[1]=1;
	ll ans=2;
	for (int i=2;i<=5002;i++){
		nm[i]=(nm[i-1]*i)%mod;
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for (int i=3;i<=n;i++){
		for (int len=2;len<=i;i++){
			for (int k=0;k<i-len;k++){
				if (s[k+len]-s[k]>a[i]*2){
					ans=ans+(nm[i-k+1]/nm[len]/nm[i-k-1-len]+mod)%mod;
				}
			}
		}
	}
	cout<<ans<<endl;
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int flag=1;
	if (n<3){
		cout<<"0"<<endl;
		return 0;
	}
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]!=1) flag=0;
	}if (n==3){
		sort(a+1,a+1+n);
		if(a[3]<a[1]+a[2]) cout<<"1"<<endl;
		else cout<<"0"<<endl;
		return 0; 
	}
	if (flag){
		work1ss();
	}else{
		work2zxss();
	}
	
	return 0;
} 
//:)
