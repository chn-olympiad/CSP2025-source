#include<bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;
const int N=2e5+10,M=6e6+10;
const ull P=131;
unordered_map<ull,int> mp;
ull p[M];
int gg[N],id[N];
string ss[N],tt[N];
vector<int> frn[M];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	p[0]=1;
	for(int i=1;i<=6e6;i++) p[i]=p[i-1]*P;
	bool flag=true;
	for(int i=1;i<=n;i++){
		int cta=0,ctb=0,ctaa=0,ctbb=0;
		string s,t;
		cin>>s>>t;
		for(int i=0;i<(int)s.size();i++){
			if(s[i]=='a') cta++;
			else if(s[i]=='b') ctb++;
			if(t[i]=='a') ctaa++;
			else if(t[i]=='b') ctbb++;
		}
		if(ctb!=1 || ctbb!=1 || cta+ctb!=(int)s.size() || ctaa+ctbb!=(int)s.size()) flag=false;
		ull ht=0;
		for(int j=0;j<(int)s.size();j++)
			ht=ht*P+s[j];
		for(int j=0;j<(int)t.size();j++)
			ht=ht*P+t[j];
		mp[ht]=1;
		ss[i]=s,tt[i]=t;
	}
	if(flag){
		for(int i=1;i<=n;i++){
			int idd=0;
			for(int j=0;j<(int)ss[i].size();j++){
				if(ss[i][j]=='b') id[i]=j;
				if(tt[i][j]=='b') idd=j;
			}
			gg[i]=id[i]-idd;
			frn[gg[i]+(int)2e6].push_back(i);
		}
		while(q--){
			string s,t;
			cin>>s>>t;
			int ids=0,idt=0;
			for(int j=0;j<(int)s.size();j++){
				if(s[j]=='b') ids=j;
				if(t[j]=='b') idt=j;
			}
			int ca=ids-idt;
			int ans=0;
			ca+=2e6;
			for(int i=0;i<(int)frn[ca].size();i++){
				int v=frn[ca][i];
				if(ss[v].size()>s.size()) continue;
				if(id[v]>ids) continue;
				if(ss[v].size()-id[v]>s.size()-ids) continue;
				ans++;
			}
			printf("%d\n",ans);
		}
		return 0;
	}
	while(q--){
		string s,t;
		cin>>s>>t;
		int qian=0,hou=s.size()-1;
		for(;qian<(int)s.size();qian++){
			if(s[qian]!=t[qian]) break;
		}
		for(;hou>=0;hou--){
			if(s[hou]!=t[hou]) break;
		}
		int ans=0;
		for(int i=0;i<(int)s.size();i++){
			if(i!=0 && s[i-1]!=t[i-1]) break;
			ull a=0,b=0;
			for(int j=i;j<(int)s.size();j++){
				a=a*P+s[j],b=b*P+t[j];
				if(j<hou) continue;
				ull g=a*p[j-i+1]+b;
				if(mp[g]) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}