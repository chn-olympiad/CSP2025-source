#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[105];
int x,p;
int ceil(int m,int n){
	if(m%n==0){
		return m/n;
	}
	return m/n+1;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	} 
	x=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			p=n*m-i+1;
		}
	}
	cout<<ceil(p,n)<<" ";
	if(ceil(p,n)%2==1){
		cout<<(p-1)%n+1;
	}
	else{
		cout<<n-(p-1)%n;
	}
}
