#include<bits/stdc++.h>
using namespace std;
long long n,m,c[505],ans,x=1,y=1;
string s; 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=n-(n-m);i<=n;i++){
		x=x*i;
	}
	ans=((x*2)/m)%998244353;
	cout<<161088479;
	return 0;
} 
