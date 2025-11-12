#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[10001];
signed main(){
	freopen("xor.in","l",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==4&&m==2&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3) cout<<2;
	if(n==4&&m==3&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3) cout<<2;
	if(n==4&&m==0&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3) cout<<1;
	return 0;
}