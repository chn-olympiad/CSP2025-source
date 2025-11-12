#include<bits/stdc++.h>
using namespace std;
int n,m,x;
bool s=0,d=0;
long long ans=0;
string a;
int b[501],c[501],k=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=0;i<n;i++){
		c[i]=a[i]-'0';
		if(c[i])s=1;
		if(!s)x++;
		if(!c[i])d=1;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	if(!d){
		ans=1;
		for(int i=1;i<=n;i++){
			ans+=ans*(n-i);
			ans%=998244353;
		}
		cout<<ans;
	}
	else if(n==m){
		cout<<ans;
	}
	else{
		sort(b+1,b+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(!(b[i]-x))break;
			k++;
		}
		ans=1;
		for(int i=1;i<n;i++){
			ans=ans*(n-i);
			ans%=998244353;
		}
		ans=ans*k;
		cout<<ans;
	}
	return 0;
}
