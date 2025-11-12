#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define ir(i,a,b) for(int i=b;i>=a;i--)
#define ll long long
using namespace std;
int cnt[114];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	string s;
	cin>>s;
	rep(i,0,s.length()-1) 
	{
		if('0'<=s[i] and s[i]<='9') cnt[s[i]-'0']++;
	}
	bool flag=0; 
	ir(i,0,9)
	{
		if(i!=0)
		{
			rep(j,1,cnt[i]) cout<<i;
			if(cnt[i]!=0) flag=1;
		} 
		else{
			if(flag==0 and cnt[i]>1) cout<<0;
			else 
			{
				rep(j,1,cnt[i]) cout<<i;
			}
		}
	}
	return 0;
 } 
