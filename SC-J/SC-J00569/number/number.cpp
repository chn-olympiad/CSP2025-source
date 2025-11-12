#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define ex exit(0);
#define pii pair<int,int> 
#define sinzo return 
#define code 0 
const int N=2e6+10;
const int mod=1e9+7;
int n,m,k,cnt,sum;
int a[N],b[N],c[N];
bool vis[N];
using namespace std;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			a[++cnt]=s[i]-'0'; 
		}
	}
	sort(a+1,a+1+cnt);
	for(int i=cnt;i;i--)cout<<a[i];
	if(cnt==n+1)
	{
		while(1)
		{
			cout<<"sinzo rp++\n";
		}
	}
	sinzo code;
} 
/*
qaq 
|s|<=1e6 !!!
*/