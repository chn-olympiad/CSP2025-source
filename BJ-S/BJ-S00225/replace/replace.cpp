#include <bits/stdc++.h>
using namespace std;
#define int long long
string s1[200010],s2[200010];
map<string,string>mp;
int n,q,l,r,ans;
string t1,t2,d1,d2,f1,f2;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		mp[s1[i]]=s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		l=0,r=0,ans=0;
		
		for(int j=0;j<t1.length();j++){
			if(t1[j]!=t2[j]){
				l=j;
				break;
			}
		}
		for(int j=t1.length()-1;j>=0;j--){
			if(t1[j]!=t2[j]){
				r=j;
				break;
			}
		}
		d1=t1.substr(l,r-l+1);
		d2=t2.substr(l,r-l+1);
		if(mp[d1]==d2) ans++;
		for(int j=l-1;j>=0;j--){
			f1=t1.substr(j,r-j+1);
			f2=t2.substr(j,r-j+1);
			if(mp[f1]==f2) ans++;
			for(int k=r+1;k<t1.length();k++){
				f1+=t1[k];
				f2+=t2[k];
				if(mp[f1]==f2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
