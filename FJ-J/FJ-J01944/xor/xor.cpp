#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=5e5+10;
int x(int a,int b){
	return a!=b;
}
int n,k,a[N],cnt;
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(k==1){
		for(int i=1;i<=n;i++)if(a[i])cnt++;
	}
	if(k==0){
		for(int i=1;i<=n;i++)if(a[i]&&a[i+1])a[i+1]=0;
		for(int i=1;i<=n;i++)if(!a[i])cnt++;
	}
	cout<<cnt;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int _=1;//cin>>_;
	while(_--)solve();
}
