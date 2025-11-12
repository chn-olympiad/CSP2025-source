#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m;
string s[N][2],q,w;
int l,r;
bool check(string s2,int wz1,string ed){
	string tmp=s[wz1][0];
	string t3=s[wz1][1];
	int len=s2.size(),len1=tmp.size();
	for(int i=0;i<len;i++){
		if(s2.substr(i,len1)==tmp){
			if(i<=l&&r<=i+len1&&ed.substr(i,len1)==t3){
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(m--){
		int ans=0;
		cin>>q>>w;
		int le=q.size();
		l=114514,r=-11451;
		for(int i=0;i<le;i++){
			if(q[i]!=w[i]){
				l=min(l,i);
				r=max(r,i);
			}
		}
		for(int i=1;i<=n;i++){
			if(s[i][0].size()<r-l+1)continue;
			if(check(q,i,w)){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
}
