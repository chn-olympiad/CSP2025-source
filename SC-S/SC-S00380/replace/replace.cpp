#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s1[N],s2[N],s3[N],s4[N];
int l[N],r[N];
string s,t;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];	
		int l1=0,r1=s1[i].size()-1;
		while(s1[i][l1]==s2[i][l1])l1++;
		while(s1[i][r1]==s2[i][r1])r1--;
		if(r1<l1)l1=0,r1=0;
		l[i]=l1,r[i]=r1;
		s3[i]=s1[i].substr(l1,r1-l1+1);
		s4[i]=s2[i].substr(l1,r1-l1+1);
//		cout<<s3[i]<<" "<<s4[i]<<'\n';
	}
	
	while(q--)
	{
		cin>>s>>t;
		int ans=0;
		int l1=0,r1=s.size()-1;
		while(s[l1]==t[l1])l1++;
		while(s[r1]==t[r1])r1--;
		if(r1<l1)r1=l1;
		string ss=s.substr(l1,r1-l1+1),tt=t.substr(l1,r1-l1+1);
//		cout<<ss<<" "<<tt<<'\n';
		for(int i=1;i<=n;i++)
			if((ss==s3[i])&&(tt==s4[i])&&l1>=l[i]&&r1>=r[i])ans++;
		cout<<ans<<'\n';
	}
	return 0;
}