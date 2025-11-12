#include<bits/stdc++.h>
using namespace std;

int n,q;
string s[200005][2],t[200005][2];
int cs[200005],ct[200005],m;
int tong[200005];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1],cs[i]=int(s[i][1].size()),m=max(cs[i],m);
	sort(cs+1,cs+n+1);
	for(int i=1;i<=n;i++){
		tong[cs[i]]=i;
	}
	for(int i=1;i<=q;i++) cin>>t[i][0]>>t[i][1],ct[i]=int(t[i][1].size()),cout<<tong[min(ct[i],m)]<<'\n';
	return 0;
}
