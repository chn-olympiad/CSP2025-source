#include<bits/stdc++.h>
using namespace std;
int a[6000],n,m=2;
long long ans=0;
void func(int x,int b,int sum){
	if(x>n)return;
	if(b<m){
		b++;
		sum+=a[x];
		func(x+1,b,sum);
		b--;
		sum-=a[x];
		func(x+1,b,sum);
	}else{
		if(sum>a[x]){
			ans++;
			ans%=998244353;
			func(x+1,b,sum);
		}else return;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n-2;i++){
		func(1,0,0);
		m++;
	}
	cout<<ans;
	return 0;
}
