#include<bits/stdc++.h>
#define int long long
using namespace  std;
const int N=1e7+7;
int n,k;
int a[N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","r",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	int x=0;
	for(int i=0;i<n;i++) x+=a[i];
	cout<<x;
	exit(0);
}
