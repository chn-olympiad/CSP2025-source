#include<bits/stdc++.h>
using namespace std;
int t,n,m,c[501];
char ch[501];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>t;
	for(int ti=1;ti<=t;ti++){
		cin>>n>>m;
		for(int i=1;i<=n;i++)	cin>>ch[i];
		for(int i=1;i<=n;i++)	cin>>c[i];
		int g=n;
		for(int i=1;i<m;i++){
			g*=(n-i);
		}
		int k=m;
		for(int i=1;i<m;i++){
			k*=(m-i);
		}
		cout<<(g/k)%998244353;
	}
	fclose(stdin);
	fclose(stdout);
} 
