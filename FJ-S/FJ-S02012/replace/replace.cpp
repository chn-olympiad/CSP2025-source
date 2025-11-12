#include<bits/stdc++.h>
using namespace std;
int n,q,ans=0;
string s[100010];
map<string,string>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		string s2;
		cin>>s[i]>>s2;
		mp[s[i]]=s2;
	}
	while(q--){
		string a,b;
		ans=0;
		cin>>a>>b;
		for(int i=0;i<a.size();i++){
			for(int j=i;j<a.size();j++){
				string l,r,z;
				for(int x=0;x<i;x++)l+=a[x];
				for(int x=i;x<=j;x++)r+=a[x];
				for(int x=j+1;x<a.size();x++)z+=a[x];
				r=mp[r];
				//cout<<l+r+z<<endl;
				if(l+r+z==b)ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
