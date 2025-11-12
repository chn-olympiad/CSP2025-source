#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,ans;
int a[N],b[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	/*
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i-1]^b[i-1];
	}
	for(int i=1;i<=n;i++)if(a[i]==k)ans++;
	//for(int i=2;i<=n;i++)if(a[i]^a[i-1]==k)ans++;
	for(int i=2;i<=n;i++)if(b[i]^b[i-1]==k||b[i]==k)ans++;
	cout<<ans;
	*/
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)if(a[i]==k)ans++;
	for(int i=2;i<=n;i++)if((a[i]^a[i-1])==k)ans++;
	cout<<ans;
	return 0;
} 
