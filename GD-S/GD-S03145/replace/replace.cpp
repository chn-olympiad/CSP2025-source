#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q,m;
string a[N][3],s1,s2,b[N][3];
map<pair<string,string>,bool > mp;
int change(string s,string t){
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=a[i][1].size();
		for(int j=0;j<s.size();j++){
			if(j+l>s.size()) break;
			string ss=s.substr(j,l),tt=t.substr(j,l);
			if(ss==a[i][1] && tt==a[i][2]){
				bool flag=0;
				for(int i=0;i<j;i++){
					if(s[i]!=t[i]){
						flag=1;
						break;
					}
				}
				for(int i=j+l;i<s.size();i++){
					if(s[i]!=t[i]){
						flag=1;
						break;
					}
				}
				if(!flag)ans++;
			}
		}
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2];
	}
	while(q--){
		cin>>s1>>s2;
		cout<<change(s1,s2)<<endl;
	}
	return 0;
}

