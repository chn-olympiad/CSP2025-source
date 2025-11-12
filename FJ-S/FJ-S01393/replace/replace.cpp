#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
int n,q;
string a[200010],b[200010];
void solve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	while(q--){
		string c,s;
		cin>>c>>s;
		string cc=c;
		int l=c.size(),ans=0;
		for(int i=1;i<=n;i++){
			cc=c;
			int f=cc.find(a[i]),la=a[i].size();
			if(f<l){
				for(int j=f;j<f+a[i].size();j++)
					cc[j]=b[i][j-f];
			}
			if(cc==s)ans++;
		}
		cout<<ans<<endl;
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num=1;
	//cin>>num;
	while(num--)solve();
	return 0;
}
