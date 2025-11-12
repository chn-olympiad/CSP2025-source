#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,st[N],ed[N];
string s1[N],s2[N],t1,t2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		if(s1[i]==s2[i]){i--,n--;continue;}
		int m=s1[i].size();
		for(int j=0;j<m;j++)
			if(s1[i][j]!=s2[i][j]){st[i]=j;break;}
		for(int j=m-1;j;j--)
			if(s1[i][j]!=s2[i][j]){ed[i]=j;break;}
	}
	while(q--)
	{
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){cout<<"0\n";continue;}
		int m=t1.size(),s=11451411,e=1e9+7;
		for(int j=0;j<m;j++)
			if(t1[j]!=t2[j]){s=j;break;}
		for(int j=m-1;j;j--)
			if(t1[j]!=t2[j]){e=j;break;}
		int ans=n;
		for(int i=1;i<=n;i++)
		{
			if(e-s!=ed[i]-st[i]||st[i]>s||s-st[i]+s1[i].size()>m){ans--;continue;}
			for(int j=0,k=s-st[i];j<s1[i].size();j++,k++)
				if(s1[i][j]!=t1[k]||s2[i][j]!=t2[k]) {ans--;break;}
		}
		cout<<ans<<'\n';
	}
}
//T3暴力打了近两个小时，还没打出来…… 
//没救了
//tried brute force for 2 hrs but failed
