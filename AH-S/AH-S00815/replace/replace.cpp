#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1,s2;
map<string,string>mp;
map<string,int>vis;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		mp[s1]=s2;vis[s1]=1;
	}
	while(q--){
		int ans=0;
		cin>>s1>>s2;
		int l=s1.size();
		for(int i=0;i<l;i++){
			for(int j=i;j<l;j++){
				string x="",y="",z="",tmp="";
				for(int k=0;k<i;k++)x+=s1[k];
				for(int k=i;k<=j;k++)y+=s1[k];
				for(int k=j+1;k<l;k++)z+=s1[k];
				if(vis[y])tmp+=mp[y];
				if(x+tmp+z==s2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
