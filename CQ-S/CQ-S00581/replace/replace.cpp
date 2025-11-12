#include<bits/stdc++.h>
#define int long long
using namespace std;
//operator
//priority
int n,q;
map<string,string> a;
string s[200010];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		a[s1]=s2;
		s[i]=s1;
	}
	for(int i=1;i<=q;i++){
		string s1,s2;
		int ans=0;
		cin>>s1>>s2;
		for(int j=1;j<=n;j++){
			if(s1.find(s[i])>=0){
				string t="";
				int f=s1.find(s[i]);
				for(int i=0;i<f;i++){
					t+=s1[i];
				}
				t+=a[s[i]];
				for(int i=f+s[i].size()+1;i<s1.size();i++){
					t+=s1[i];
				}
				if(t==s2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
