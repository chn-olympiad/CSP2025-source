#include<bits/stdc++.h>
using namespace std;
const int N=1e5+20;
const long long mod=998244353;
int n,m;
//记得检查盘，存盘，freopen，删注释，删文件 
char a[520];
int c[N],t[N],cnt,k,ans;
long long jc[N]; 
void gb(int l,int r)
{
	if(r==l)
	{
		return ;
	}
	int mid=(l+r)>>1;
	gb(l,mid);
	gb(mid+1,r);
	for(int i=l,j=l,k=mid+1;i<=r;++i)
	{
		if(j==mid+1)
		{
			t[i]=c[k++];
		}
		else if(k==r+1)
		{
			t[i]=c[j++];
		}
		else
		{
			t[i]=c[j]<c[k]?c[j++]:c[k++];
		}
	}
	for(int i=l;i<=r;++i)
	{
		c[i]=t[i];
	}
	return ;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	jc[0]=1;
	for(int i=1;i<=n;++i)
	{
		jc[i]=jc[i-1]*i;
		jc[i]%=mod;
	}
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		cnt+=a[i]-'0';
	}
	for(int i=1;i<=n;++i)
	{
		cin>>c[i];
	}
	gb(1,n);
	if(cnt<m)
	{
		cout<<0;
	}
	else if(c[1]>=n)
	{
		cout<<jc[n];
	}
	else
	{
		for(int i=1;i<=n;++i)
		{
			if(c[i]>=k)
			{
				ans++;
			}
		}
		cout<<(jc[2]*ans)%mod*jc[n-k]%mod;
	}
//	cout<<'\n'<<"多组数据要换行&初始化"; 
//	cout<<'\n'<<"删注释&这句话&.exe&.out！！！！！！";
//	cout<<'\n'<<"删注释&这句话&.exe&.out！！！！！！";
//	cout<<'\n'<<"删注释&这句话&.exe&.out！！！！！！";
//	cout<<'\n'<<"删注释&这句话&.exe&.out！！！！！！";
//	cout<<'\n'<<"删注释&这句话&.exe&.out！！！！！！";
//	cout<<'\n'<<"删注释&这句话&.exe&.out！！！！！！";
	return 0;
}
//struct 
