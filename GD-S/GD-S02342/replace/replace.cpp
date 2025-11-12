#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=2e5+10;
int n,t,b1[N],b2[N];
string s1[N],s2[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		for(int j=0;j<s1[i].size();j++)
			if(s1[i][j]=='b'){
				b1[i]=j;
				break;
			}
		for(int j=0;j<s2[i].size();j++)
			if(s2[i][j]=='b'){
				b2[i]=j;
				break;
			}
	}
	while(t--){
		int ans=0,t1b,t2b;
		string t1,t2;
		cin>>t1>>t2;
		for(int i=0;i<t1.size();i++)
			if(t1[i]=='b'){
				t1b=i;
				break;
			}
		for(int i=0;i<t2.size();i++)
			if(t2[i]=='b'){
				t2b=i;
				break;
			}
		for(int i=1;i<=n;i++){
			if((t1b>=b1[i]&&s1[i].size()-b1[i]>=t1.size()-t1b)||(t2b>=b2[i]&&s2[i].size()-b2[i]>=t2.size()-t2b)){
				if(t2b-t1b==b2[i]-b1[i]) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
