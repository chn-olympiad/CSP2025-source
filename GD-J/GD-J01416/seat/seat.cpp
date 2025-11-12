#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],f;
int le;
bool cmp(int o,int p){
	return o>p;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	f=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==f){
			f=i;
			break;
		}
	}
	le=(f/n)+(f%n>0);
	cout<<le<<" ";
	if(le%2==1){
		if(f%n==0) cout<<n;
		else cout<<f%n;
	}
	if(le%2==0){
		if(f%n==0) cout<<1;
		else cout<<n-f%n+1;
	}
	return 0;
} 
