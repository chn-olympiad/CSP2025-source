#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+7;
struct node{
	string s,t;
}a[N];
int n,q;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].t;
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		int sum=0;
		for(int i=0;i<max(t1.size(),t2.size());i++){
			if(i==min(t1.size(),t2.size())){
				sum+=max(t1.size(),t2.size())-i;
				break;
			}
			if(t1[i]!=t2[i]){
				sum++;
			}
		}
		for(int i=1;i<=n;i++){
			if(t1.find(a[i].s)!=t1.npos&&t2.find(a[i].t)!=t2.npos&&(a[i].t.size()==sum||(a[i].t==t2&&a[i].s==t1))){
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
