#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
map<string,int> mp;
int top;
signed main(){
	freopen("replace.in","r",stdout);
	freopen("replace.out","w",stdin);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
//		for(int t=0;t<s1.size();t++){
//			if(s1[t]==s2[t]) top1++;
//			else break;
//		}
//		for(int i=s1.size()-1;i>=0;i--){
//			if(s1[i]==s2[i]) top2=i;
//			else break;
//		}
//		string fs="",bs="";
//		for(int i=0;i<=top1;i++) qs+=s1[i];
//		for(int j=top2;j<=s1.size();j++) hs+=s1[i];
//		a[i].f=s1,a[i].s=s2,a[i].qc=qc,a[i].hc=hc;
		mp[s1]=mp[s2]=i;
	}
	int sx=0;
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int ans=0,top1=0,top2=0;
		for(int t=0;t<s1.size();t++){
			if(s1[t]!=s2[t]){
				top1=t;
				break;
			}
		}
		for(int i=s1.size()-1;i>=0;i--){
			if(s1[i]!=s2[i]){
				top2=i;
				break;
			}
		}
		for(int i=top1;i>=0;i--){
			for(int j=top2;j<s1.size();j++){
				string fs="",bs="";
				for(int k=i;k<=j;k++) fs=fs+s1[k],bs=bs+s2[k];
				//cout<<fs<<" "<<bs<<endl;
				if(mp[fs]==mp[bs]&&mp[fs]!=0) ans++;
			}
		}
		cout<<ans<<endl;
//		string fs="",bs="";
//		for(int i=0;i<=top1;i++) s+=s1[i];
//		for(int i=top2;i<s.size();i++) s+=s2[i];
//		for(int i=1;i<=n;i++) mp[s+a[i].f]=mp[s+a[i].s]=n+i;
//		for(int i=1;i<=n;i++){
//			for(int j=0;j<min(s1.a[i].f.size(),s.size());j++){
//				if(s[top1-j]==s1[j]) mp[]
//			}
//		}
	}
}
