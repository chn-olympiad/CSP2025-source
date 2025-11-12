#include<bits/stdc++.h>
using namespace std;
string s[200100],s1[200100],t1,t2,tmp,tmp1;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i]>>s1[i];
	while(q--){
		int ans=0;
		string tmp;
		cin>>t1>>t2;
		for(int j=0;j<t1.size();j++){
			if(t1[j]!=t2[j]){
				tmp+=t2[j],tmp1+=t1[j];
			}
		}
		for(int i=1;i<=n;i++)
			if(tmp1==s[i]&&s1[i]==tmp) ans++;
		cout<<ans<<endl;
	}
	return 0;
}
