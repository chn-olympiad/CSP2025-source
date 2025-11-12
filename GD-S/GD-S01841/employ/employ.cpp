#include<bits/stdc++.h>
using namespace std;
const int maxn=605;
int a[maxn],c[maxn];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++){
		if(a[i]==1)cnt++;
	}
	if(m>n-cnt)cout<<0<<endl;
	return 0;
}
