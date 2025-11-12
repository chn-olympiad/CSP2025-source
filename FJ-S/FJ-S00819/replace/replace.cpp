#include<bits/stdc++.h>
using namespace std;
bool check1(string a,string b)
{
	bool ck=true;
	for(int i=0;i<sizeof(b);i++)
	{
		if(b[i]==a[0])
		{
			for(int j=i;j<i+sizeof(a);j++)
			{
				ck=ck&&(b[j]==a[j-i]);
			}
			if(ck)return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	string t1[99],t2[99],str,s1[99],s2[99];
	int l,r,ans=0;
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	for(int i=0;i<q;i++)
	{
		cin>>t1[i]>>t2[i];
	}
for(int s=0;s<q;s++)
{
	l=0;while(t1[s][l]==t2[s][l])l++;
	r=t1[s].size();while(t1[s][r]==t2[s][r])r--;
	for(int j=l;j<r;j++)str+=t1[s][j];
	for(int i=0;i<n;i++)
	{
		if(check1(str,s1[i]))
		{
			if(check1(s1[i],t1[s]))
			{
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
	return 0;
}

