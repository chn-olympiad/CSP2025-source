//just pianfen!!!
//Can I get 1= with 149 pts???(SC)
//maybe,it like 2023(maybe orange green+ blue purple-) 
//WHY SO HARD!!!!!
//...
//Alright,I have many chance because I'm Grade 8
//So let's work together to prepare CSP2026!
//luogu:zhangjizhi
//I want to let this in sichuan mihuo action show
//CCFCCFCCFCCFCCFCCFCCFCCF
#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s1[200001],s2[200001],l1[200001],l2[200001],ava[200001];
int n,q,flag=1;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i],flag=min(flag,(s1[i]=='a'&&s1[i]=='b'&&s2[i]=='a'&&s2[i]=='b'));
	for(int i=1;i<=q;i++) cin>>l1[i]>>l2[i],flag=min(flag,(l1[i]=='a'&&l1[i]=='b'&&l2[i]=='a'&&l2[i]=='b'));
	else if(flag)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<s1[i].size();j++)
			{
				if(s1[i][j]=='b') ava[i]=min(j,s1[i].size()-1-j);
			}
		}
		sort(ava+1,ava+n+1);
		for(int i=1;i<=q;i++)
		{
			for(int j=0;j<s1[i].size();j++)
			{
				if(s1[i][j]=='b') ava[i+n]=max(j,s1[i].size()-1-j);
			}
		}
		sort(ava+n+1,ava+n+q+1);
		int tp=1,ans=0;
		for(int i=1;i<=q;i++)
		{
			while(1)
			{
				if(ava[tp]>ava[n+i]||tp==n+1) break;
				ans+=(q-i+1);
			}
		}
		cout<<ans;
	}
	else
	{
		for(int i=1;i<=q;i++) cout<<0;
	}
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/