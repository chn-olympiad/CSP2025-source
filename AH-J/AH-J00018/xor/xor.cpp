#include<bits/stdc++.h>
using namespace std;
int n,m,ans,sum,a[500010],k;
map <int ,int > g;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sum=0;
	for(int i=0;i<=n;i++){
		sum^=a[i];
		if(g[sum^k]>0){
			ans++;
			g.clear();
		}
		g[sum]++;
	}
	cout<<ans;
	return 0;
}
