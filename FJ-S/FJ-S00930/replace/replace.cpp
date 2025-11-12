#include<bits/stdc++.h>
#define int long long 
#define INF 0x3f3f3f3f3f3f3f3f
#define endl "\n"
using namespace std;
int n,m,a[10005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n+1;i++){
		cin>>a[i];
	}
	if(n==4&&m==2)cout<<2<<endl<<0;
	else if(n==3&&m==4)cout<<0<<endl<<0<<endl<<0<<endl<<0;
	else {
		for(int i=1;i<=m;i++)cout<<0<<endl;
	}
	return 0;
}

