#include<bits/stdc++.h>
#define ll long long
using namespace std;
string t1,t2,s1,s2;
unordered_map<string,string> mp;
const int MAXN=2e5+10;
int n,m;
ll ans;
string s[MAXN];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s1;
		s[i]=s1;
		cin>>s2;
		mp[s1]=s2;
	}
	while(m--){
		ans=0;
		cin>>t1;
		cin>>t2;
		for(int i=1;i<=n;i++){
			for(int j=0;j+s[i].size()<=t1.size();j++){
				if(s[i][0]==t1[j]){
//					cout<<i<<' '<<j<<"#"<<endl;
					bool tf=1;
					for(int k=0;k<s[i].size();k++){
						if(s[i][k]!=t1[j+k]){
							tf=0;
							break;
						}
					}
					if(tf==0) continue;
					string now="";
					string pre1="",bk1="",pre2="",bk2="";
					for(int k=0;k<j;k++){
						pre1=pre1+t1[k];
						pre2=pre2+t2[k];
					}
					for(int k=j;k<j+s[i].size();k++){
						now=now+t2[k];
					}
					for(int k=j+s[i].size();k<t1.size();k++){
						bk1=bk1+t1[k];
						bk2=bk2+t2[k];
					}
					if(now==mp[s[i]]&&pre1==pre2&&bk1==bk2){
						ans++;
//						cout<<pre1<<now<<bk1<<endl;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}
