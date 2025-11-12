#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,q,ans;
string s1[200010],s2[200010];
string t1[200010],t2[200010];

void dfs(string a,string b){
	for(int i=1;i<=n;i++){
		if(t1[i].size()>a.size()) continue;
		for(int j=0;j+t1[i].size()<=a.size();j++){
			string l;
			for(int k=0;k<t1[i].size();k++){
				l=l+a[j+k];
			}
			if(l==t1[i]){
				l=a;
				for(int k=j;k<j+t1[i].size();k++){
					l[k]=t2[i][k-j];
				}
				if(l==b) ans++; 
			}
		}
	}
	return ;
}

signed main( ){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=q;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=n;i++){
		cin>>t1[i]>>t2[i];
	}
	for(int i=1;i<=q;i++){
		ans=0;
		dfs(s1[i],s2[i]);
		cout<<ans<<endl;
	}
	return 0;
}

