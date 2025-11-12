#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
struct re{
	string x,y;
}a[N];
int n,q;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<"0\n";
			continue;
		}
		int len=s1.size();
		int ans=0;
		for(int i=1;i<=n;i++){
			int cnt=0;
			while(s1.find(a[i].x,cnt)!=-1){
				cnt=s1.find(a[i].x,cnt)+1;
				string s=s1;
				s.erase(cnt-1,a[i].x.size());
				s.insert(cnt-1,a[i].y);
				if(s==s2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
