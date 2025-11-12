#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200010][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
	while(q--){
		string t1,t2;cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";continue;
		}
		int p=200010,l=0;
		for(int i=0;i<t1.size();i++){
			if(t1[i]!=t2[i])p=min(p,i),l=i;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(t1.find(s[i][0])==t1.npos)continue;
			if(t2.find(s[i][1])==t2.npos)continue;
			int f1=t1.find(s[i][0]),f2=t2.find(s[i][1]);
			if(f1>p||f1+s[i][0].size()-1<l||f2>p||f2+s[i][1].size()-1<l)continue;
			ans+=(f1==f2);
		}
		cout<<ans<<'\n';
	}
}
