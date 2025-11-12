#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
//这 m小木棍能拼成一个多边形
//当且仅当 m>=3且所有小木棍的长度之和
//大于所有小木棍的长度最大值的两倍
int n;
int a[5005];
int max_stick=-1;

bool cmp(int x,int y)
{
	if(x>y)
		return 1;
	else
		return 0;
}

int search(int start,int cside,int ns,int limit)
{
	
	int sum=0;
	if(cside==ns)
	{
		max_stick=a[start];
		limit=2*max_stick;
	}
	cerr<<start<<" "<<cside<<" "<<ns<<" "<<limit<<endl;
	if(cside==0 && limit<0)
	{
		cerr<<"return 1-------------"<<endl;
		return 1;
	}
	if(cside==0 && limit>=0) return 0;
	for(int i=start;i<=n;i++)
	{
		cerr <<cside<<"chose:"<< a[i] <<"  "<<ns<< endl;
		sum += search(i+1,cside-1,ns,limit-a[i])%MOD;
		sum%=MOD;
	}
	
	return sum;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	int ans=0;
	for(int i=3;i<=n;i++)
	{
		
		ans=(search(1,i,i,-1)%MOD+ans%MOD)%MOD;
		cerr<<"____________________________"<<endl;
	}
	cout << ans << endl;
	return 0;
}
