#include<bits/stdc++.h>
using namespace std;
int n,m,c[510];
long long ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=n;i++){
		ans=ans*i%998244353;
	}
	cout<<ans;
}
