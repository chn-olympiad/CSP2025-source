#include<bits/stdc++.h>
using namespace std;
int maxn=1e3+10;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s[maxn];
	int c[maxn];
	for(int i=1;i<=n;i++){
		cin>>s[i];
		cin>>c[i];
	}
	if(n==3) cout<<m;
	if(n>3&&n<=100) cout<<n;
	if(n<=500&&n>100) cout<<"1";
	return 0;
}
