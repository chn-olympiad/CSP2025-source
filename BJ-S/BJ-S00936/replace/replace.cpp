#include<bits/stdc++.h>
using namespace std;
struct node{
	string a,b;
}s[200010];
map<string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
		mp[s[i].a]=s[i].b;
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		int ans=0;
		for(int i=0;i<a.size();i++){
			for(int j=i;j<a.size();j++){
				string st=a.substr(i,j-i+1);
				string sr=mp[st];
				string a2=a;
				for(int w=i;w<=j;w++) a[w]=sr[w-i];
				if(a==b) ans++;
				a=a2;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}