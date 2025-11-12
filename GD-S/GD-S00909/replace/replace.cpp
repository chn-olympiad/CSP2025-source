#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;
typedef long long ll;
const int ma=2e5+5;
string s[ma][5];
unordered_map<string,string> re;
string cut(string s,int l,int r){
	string ans;
	for(int i=l;i<=r;i++){
		ans+=s[i];
	}
	return ans;
}
int main(){
  freopen("replace.in","r",stdin);
  freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=q;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		re[s1]=s2;
	}
	ll ans=0;
	for(int i=1;i<=q;i++){
		ans=0;
		for(int l=0;l<=s[i][1].size()-1;l++){
			for(int r=s[i][1].size()-1;r>=0;r--){
				string now=cut(s[i][1],l,r);
				now=re[now];
				now=cut(s[i][1],0,l-1)+now+cut(s[i][1],r+1,(int)s[i][1].size()-1);
				if(now==s[i][2])ans++;
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}

