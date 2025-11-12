#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q;
string s1[N],s2[N];
bool check1(int l,int r,string &s,string &t){
	for(int i=l;i<=r;i++)if(s[i]!=t[i])return 0;
	return 1;
}
bool check2(int x,int y,string &s,string &t){
	for(int i=0;i<y;i++)if(s[i]!=t[i+x])return 0;
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int ans=0,T=t1.size();
		for(int i=1;i<=n;i++){
			int S=s1[i].size();
			for(int j=0;j+S<=T;j++){
				bool p=check1(0,j-1,t1,t2)&&check1(j+S,T-1,t1,t2)&&check2(j,S,s1[i],t1)&&check2(j,S,s2[i],t2);
				ans+=p;
			}
		}
		cout<<ans<<'\n';
	}
}
