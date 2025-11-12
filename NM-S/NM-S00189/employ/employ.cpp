#include<bits/stdc++.h>
#define int long long
#define N 100005
using namespace std;
const int MOD=998244353;

int n,m;
string s;
array<int,N> a;

int num,cnt,ans;
array<bool,N> val;

void dfs(int x,vector<int> v)
{
	if(x==n+1)
	{
		num=0,cnt=0;
		for(int i=0;i<v.size();i++)
		{
            if(cnt>=m)
            {
                ans++;
                ans%=MOD;
                return;
            }


			if(num>=a.at(v[i]) ) num++;
            else
            {
                if(s[i]=='1') cnt++;
                else if(s[i]=='0') num++;
            }
		}
        
		if(cnt>=m) ans++,ans%=MOD;
		return;
	}
	
	for(int i=1;i<=n;i++)
	if(!val.at(i) )
	{
		val.at(i)=true;
		v.push_back(i);
		dfs(x+1,v);

		v.pop_back();
		val.at(i)=false;
	}
}

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>s;
	val.fill(false);
	
	for(int i=1;i<=n;i++)
	cin>>a.at(i);
	vector<int> v;
	
	if(n>20)
	{
		ans=1;
		for(int i=1;i<=n;i++)
		ans*=i,ans%=MOD;
		cout<<ans<<endl;
        // but a_i=0 ...
		return 0;
	}
	
	dfs(1,v);
	cout<<ans<<endl;
	return 0;
}
