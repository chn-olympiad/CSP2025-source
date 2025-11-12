#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int a[N],b[N],c[N];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,m,res=0;
		cin>>n;
		m=n/2;
		for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=m;i++)res+=a[i];
		cout<<res<<"\n";
	}
	return 0;
}
