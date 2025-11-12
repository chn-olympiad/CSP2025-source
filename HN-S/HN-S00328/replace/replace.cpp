#include<bits/stdc++.h>
using namespace std;
int n,q;
map<pair<string,string>,int>vis;
string s1[200005],s2[200005],t1,t2;
int pos[200005];
int ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		vis[{s1[i],s2[i]}]++;
		pos[i]=s1[i].find('b');
	} 
	int len;
	while(q--){
		cin>>t1>>t2;
		len=t1.size();
		ans=0;
		if(len<=2000){
			string s,ss;
			string f1="",f2="";
			for(int i=0;i<len;i++){
				s=ss="";
				if(f1!=f2){
					break;
				}
				for(int j=i;j<len;j++){
					s+=t1[j];ss+=t2[j];
					if(j==len-1 || t1.substr(j+1)==t2.substr(j+1)){
						ans+=vis[{s,ss}];
					}
				}
				f1+=t1[i];f2+=t2[i];
			}
			cout<<ans<<"\n";
			continue;
		}
		int f=t1.find('b');
		string s;
		for(int i=1;i<=n;i++){
			s="";
			if(s1[i].size()>t1.size()){
				continue;
			}
			bool flag=0;
			for(int j=0;j<f-pos[i];j++){
				if(t1[j]!=t2[j]){
					flag=1;
					continue;
				}
			}
			if(flag){
				continue;
			}
			for(int j=f-pos[i];j<=f-pos[i]+s1[i].size()-1;j++){
				if(s1[i][j-(f-pos[i]+1)]!=t2[j]){
					flag=1;
				}
			}
			if(flag){
				continue;
			}
			for(int j=f-pos[i]+s1[i].size();j<t1.size();j++){
				if(t1[j]!=t2[j]){
					flag=1;
				}
			}
			if(!flag){
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
