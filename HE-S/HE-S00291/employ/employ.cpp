#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<queue>
using namespace std;
int n,m;
char hard[1000];
int c[1000];
long long use[1000];
bool can[1000];
const int mod=998244353;
int go[1000];
map<long long,long long> mp;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	//记得解注释!!!!!!!
	
	//对于特殊性质a
	//c【i】=0需要特殊考虑
	//但我燃尽了 
	//我要回去看第一题了 
	bool te=true;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		go[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>hard[i];
		if(hard[i]=='0')
		{
			te=false;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		mp[c[i]]++;
	}
	if(te)
	{
		long long suan=1;
		for(int i=1;i<=n;i++)
		{
			suan*=i;
			suan%=mod;
		}
		cout<<suan%mod;
	}
	else if(n<=10)
	{
		long long ans=0;
		do
		{
			int ji=0;
			for(int i=1;i<=n;i++)
			{
				if(ji>=c[go[i]]||hard[i]=='0')
				{
					ji++;
				}
			}
			if(n-ji>=m)
			{
				ans++;
				ans%=mod;
			}
		
		}while(next_permutation(go+1,go+1+n));
		cout<<ans%mod;
	}
	//把两个耐心相等的人交换位置对于结果没有影响
	//但对答案个数有影响 故而再进行一次单独全排列即可 
	return 0;
}
