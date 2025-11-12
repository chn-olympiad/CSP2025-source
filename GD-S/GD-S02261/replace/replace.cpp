#include<bits/stdc++.h>
using namespace std;
#define N 200005
int m,n,j,k,l,q;
map<string,string>mp;
string a[N],b,c;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>b;
		mp[a[i]]=b;
	}
	while(q--){
		cin>>b>>c;
		int ans=0;
		for(int i=1;i<=n;i++){
			int f=b.find(a[i]);
			int len=a[i].size();
			int len1=b.size()-1;
			if(f==-1)continue;
			if(c.substr(0,f)!=b.substr(0,f))continue;
			if(c.substr(f+len,len1-f+1)!=b.substr(f+len,len1-f+1))continue;
			if(c.substr(f,len)==mp[a[i]])ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
 } 
