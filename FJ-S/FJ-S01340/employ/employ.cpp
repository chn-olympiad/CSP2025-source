#include<bits/stdc++.h>
using namespace std;
#define N 100001
char s[N];
int n,m,c[N];
int main(){
	freopen("employ","r",stdin);
	freopen("employ","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int ans=1;
	for(int i=2;i<=n;i++){
		ans=ans*i%998244353;
	}
	cout<<ans<<endl;
	return 0;
}
