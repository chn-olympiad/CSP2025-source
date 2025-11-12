#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
const int M=2147483647;
string s1,s2;
struct node{
	int a,b;
}djb[200010];
long long hsh(string s,int l,int r)
{
	int ha=1331;
	long long po=0;
	for(int i=r;i>=l;i--)
		po=po*ha+(s[i]-'a');
	return po;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		int l=0,r=s1.size()-1;
		while(s1[l]==s2[l])l+=1;
		while(s1[r]==s2[r])r-=1;
		djb[i].a=hsh(s1,l,r);
		djb[i].b=hsh(s2,l,r);
	}
	for(int i=1;i<=q;i++)
	{
		int ans=0;
		cin>>s1>>s2;
		if(s1.size()!=s2.size())cout<<0<<endl;
		else
		{
			int l=0,r=s1.size()-1;
			while(s1[l]==s2[l])l+=1;
			while(s1[r]==s2[r])r-=1;
			int q=hsh(s1,l,r),w=hsh(s2,l,r);
			for(int i=1;i<=n;i++)
				if(q==djb[i].a&&w==djb[i].b)ans+=1;
			cout<<ans<<endl;	
		}
	}
	return 0;
}
