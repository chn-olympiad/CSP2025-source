#include<bits/stdc++.h>
using namespace std;
map<string,string> mp;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	for(int i=1;i<=q;i++){
		string s1,s2,ex;
		cin>>s1>>s2;
		ex=s1;
		if(s1.size()!=s2.size()){
			cout<<0<<endl;
			break;
		}
		int ans=0;
		for(auto it=mp.begin();it!=mp.end();it++){
			string a=it->first,b=it->second;
			ex=s1;
			int x=0;
			bool bz=0;
			for(int j=0;j<s1.size();j++){
				if(x==a.size()&&ex==s2){
					break;
				}
				if(s1[j]==a[x]&&s2[j]==b[x]){
					bz=1;
					ex[j]=b[x];
					x++;
				}else{
					bz=0;
				}
			}
			if(bz==1){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

