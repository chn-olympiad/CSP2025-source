#include<bits/stdc++.h>
using namespace std;

const int _=2e5+5;

int n,q,ans;
string s[_][3];

void solve(string s1,string s2,int id){
	string t1=s[id][1],t2=s[id][2];
	for(int l=0;l<=s1.size()-t1.size();l++){
		if(s1[l]==t1[0]){
			int flag=1;
			for(int i=0;i<t1.size();i++){
				if(s1[l+i]!=t1[i])flag=0;
				if(s2[l+i]!=t2[i])flag=0;
				if(!flag)break;
			}
			if(flag){
				for(int i=l+t1.size();i<s1.size();i++)if(s1[i]!=s2[i])return;
//				cout<<':'<<id<<endl;
				++ans;
				return;
			}
		}
		if(s1[l]!=s2[l])return;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][1]>>s[i][2];
	for(string s1,s2;q--;){
		ans=0;
		cin>>s1>>s2;
		for(int i=1;i<=n;i++)solve(s1,s2,i);
		cout<<ans<<'\n';
	}
	return 0;
}
