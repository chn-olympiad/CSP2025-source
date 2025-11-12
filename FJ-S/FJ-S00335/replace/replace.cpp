#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,q,ans;
string s1[N],s2[N];
string sx[N],sy[N],pre[N],lst[N];
string t1,t2,pt,lt,x,y,s,ppp;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>s1[i]>>s2[i];
		bool f=0;
		ppp=s="";
		for(int j=0;j<s1[i].size();j++) {
			if(s1[i][j]!=s2[i][j]) {
				f=1;
				int x=j;
				sx[i]+=s;
				while(s1[i][x]!=s2[i][x]&&x<s1[i].size()) sx[i]+=s1[i][x],sy[i]+=s2[i][x],x++;
				j=x;
			}
			if(j>=s1[i].size()) break;
			if(f) s+=s1[i][j];
			else ppp+=s1[i][j];
		}
		for(int j=ppp.size()-1;j>=0;j--) pre[i]+=ppp[j]; 
		lst[i]=s;
	}
	while(q--) {
		cin>>t1>>t2;
		if(t1.size()!=t2.size()) {puts("0");continue;}
		x=y=pt=lt=ppp=s="";
		bool f=0;
		for(int j=0;j<t1.size();j++) {
			if(t1[j]!=t2[j]) {
				f=1;
				int cc=j;
				x+=s;
				while(t1[cc]!=t2[cc]&&cc<t1.size()) x+=t1[cc],y+=t2[cc],cc++;
				j=cc;
			}
			if(j>=t1.size()) break;
			if(f) s+=t1[j];
			else ppp+=t1[j];
		}
		for(int j=ppp.size()-1;j>=0;j--) pt+=ppp[j]; 
		lt=s,ans=0;
		for(int i=1;i<=n;i++) {
			if(x!=sx[i]||y!=sy[i]) continue;
			if(pt.size()<pre[i].size()||lt.size()<lst[i].size()) continue;
			if(pt.substr(0,pre[i].size())!=pre[i]||lt.substr(0,lst[i].size())!=lst[i]) continue;
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

