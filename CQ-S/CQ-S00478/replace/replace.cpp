#include<bits/stdc++.h>
using namespace std;
int n,m,l,r;
string s1[200005];
string s2[200005];
int le[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		le[i]=s1[i].size();
	}
	while(m--){
		string a,b;
		cin>>a>>b;
		int len=a.size(),ans=0;
		if(len!=b.size()){
			cout<<"0"<<'\n';
			continue;
		}
		l=0,r=len+1;
		a=" "+a,b=" "+b;
		for(int i=1;i<=len;i++){
			if(a[i]==b[i]) l=i;
			else break;
		}
		for(int i=len;i>=1;i--){
			if(a[i]==b[i]) r=i;
			else break;
		}
		for(int i=1;i<=n;i++){
			if(le[i]<r-l-1) continue;
			for(int j=r-le[i];j<=l+1;j++){
				string ss1=a.substr(j,le[i]);
				string ss2=b.substr(j,le[i]);
				if(ss1==s1[i]&&ss2==s2[i]) ans++;
			}
		}cout<<ans<<'\n';
	}
	return 0;
}

