#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=2e5+5;
int n,q;
string t,tt,s[maxn],ss[maxn];
bool check(int x,int y){
	bool flag=1;
	for(int i=0;i<(int)s[x].size();i++){
		if(s[x][i]!=t[i+y]||ss[x][i]!=tt[i+y]){
			flag=0;
			break;
		}
	}
	for(int i=0;i<y;i++){
		if(t[i]!=tt[i]){
			flag=0;
			break;
		}
	}
	for(int i=s[x].size()+y;i<=t.size();i++){
		if(t[i]!=tt[i]){
			flag=0;
			break;
		}
	}
	return flag;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i]>>ss[i];
	while(q--){
		int ans=0;
		cin>>t>>tt;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=((int)t.size()-(int)s[i].size());j++){
				if(check(i,j))ans++;
			}
		}
		cout<<ans<<"\n";
	}
}
//10pts+
