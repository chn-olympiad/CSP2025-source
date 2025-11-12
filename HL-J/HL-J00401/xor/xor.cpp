#include<iostream>
#include<cstdio>
using namespace std;
int a[500001],x[500001],top=0,n,k,ans=0;
void solve(int p){
	for(int i=0;i<top;i++)x[i]^=p;
}
int check(){
	for(int i=0;i<top;i++)if(x[i]==k)return i;
	return -1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for(int i=0;i<n;i++)cin >> a[i];
	for(int i=0;i<n;i++){
		solve(a[i]);
		x[top++]=a[i];
		int p=check();
		if(p!=-1){
			ans++;
			top=0;
		}
	}
	cout << ans;
	return 0; 
}
