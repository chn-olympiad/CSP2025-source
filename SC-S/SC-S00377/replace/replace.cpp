#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5+10;
int n,q;
string s1[MAXN],s2[MAXN];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(t1.find(s1[i])<0) continue;
			int st=t1.find(s1[i]);
			int len=s1[i].size();
			string x,z;
			for(int i=0;i<st;i++) x+=t1[i];
			int len2=t1.size()-1;
			for(int i=st+len;i<=len2;i++) z+=t1[i];
			string now=x+s2[i]+z;
			if(now==t2) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}