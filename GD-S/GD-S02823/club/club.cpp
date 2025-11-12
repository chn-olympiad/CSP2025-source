#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+3;
int n,a[MAXN],b[MAXN],c[MAXN],id[MAXN];
bool cmp(int x,int y){
	if(a[x]-b[x]!=a[y]-b[y])return (a[x]-b[x])>(a[y]-b[y]);
	return a[x]>a[y];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			id[i]=i;
		}
		int ans=0;
		sort(id+1,id+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(i<=n/2)ans+=a[id[i]];
			else ans+=b[id[i]];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
