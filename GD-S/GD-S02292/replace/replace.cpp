#include<bits/stdc++.h>
using namespace std;
int n,q,h1[200001],h2[200001],h3[200001],h4[200001],x,y,z,w,ans;
string s1,s2;
int g1[200001],g2[200001];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		for(int i=0;s1[i]=='a';i++) h1[i]++;
		for(int i=0;s2[i]=='a';i++) h2[i]++;
		h3[i]=s1.size()-h1[i]-1,h4[i]=s2.size()-h2[i]-1;
	}
	while(q--)
	{
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<0<<endl;
			continue;
		}
		for(int i=0;s1[i]=='a';i++) x++;
		for(int i=0;s2[i]=='a';i++) y++;
		z=s1.size()-x-1,w=s2.size()-y-1,ans=0;
		for(int i=1;i<=n;i++)
			if(x>=h1[i]&&z>=h3[i]&&x-h1[i]+h2[i]==y&&z-h3[i]+h4[i]==w) ans++;
		cout<<ans<<endl;
	}
	return 0;
}
