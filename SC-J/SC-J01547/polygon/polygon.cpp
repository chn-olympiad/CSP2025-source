#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=5e3+5;
int a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==3){
		int maxn=max(a[1],max(a[2],a[3]));
		if(a[1]+a[2]+a[3]-maxn>maxn) cout<<1;
		else cout<<0;
	}
	
	return 0;
}