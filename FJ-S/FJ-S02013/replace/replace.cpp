#include<bits/stdc++.h>
#define ull unsigned long long
#define int long long
using namespace std;
int n,q,L1;
int h(string s,int l,int r){
	ull x=0;
	for(int i=l-1;i<=r-1;i++)x=x*13331+s[i]-'a'+1;
	return x;
}
string s1[200010],s2[200010];
int p1[200010],p2[200010];
map<int,set<int>>mp;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		L1+=s1[i].size();L1+=s2[i].size();
	}
	if(n<=1000&&q<=1000&&L1<=2000){
		for(int i=1;i<=n;i++)mp[h(s1[i],1,s1[i].size())].insert(h(s2[i],1,s2[i].size()));
		for(int i=1;i<=q;i++){
			int ans=0,l,r;
			string t1,t2;
			cin>>t1>>t2;
			for(int i=0;i<t1.size();i++)if(t1[i]!=t2[i]){l=i;break;}
			for(int i=t1.size()-1;i>=0;i--)if(t1[i]!=t2[i]){r=i;break;}
			for(int j=0;j<=l;j++){
				ull x1=0,x2=0;
				for(int k=j;k<t1.size();k++){
					x1=x1*13331+t1[k]-'a'+1;
					x2=x2*13331+t2[k]-'a'+1;
					if(k>=r&&mp[x1].size()&&mp[x1].find(x2)!=mp[x1].end())ans++;
				}
			}
			cout<<ans<<"\n";
		}
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=0;j<s1[i].size();j++){
				if(s1[i][j]=='b')p1[i]=j;
				if(s2[i][j]=='b')p2[i]=j;
			}
		}
		for(int i=1;i<=q;i++){
			string t1,t2;
			int p3,p4;
			int ans=0;
			cin>>t1>>t2;
			for(int j=0;j<t1.size();j++){
				if(t1[j]=='b')p3=j;
				if(t2[j]=='b')p4=j;
			}
			for(int j=1;j<=n;j++){
				if(p1[j]-p2[j]!=p3-p4)continue;
				if(p1[j]<p2[j]&&p1[j]<=p3&&s1[j].size()+p3-p1[j]<=t1.size())ans++;
				if(p1[j]>p2[j]&&p2[j]<=p4&&s1[j].size()+p4-p2[j]<=t1.size())ans++;
			}
			cout<<ans<<"\n";
		}
	}
}
/*
17421742174217421742174217421742174217421742174217421742174217
*/
