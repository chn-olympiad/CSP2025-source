#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define sinzo return
#define code 0
#define pii pair<int,int> 
#define ex exit(0)
using namespace std;
const int N=2e6+10;
const int mod=998244353;
int b[N],c[N],a[N];
int n,m,k,l,cnt,sum,ans,tsf=1;

string s;
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<=n;i++)
	{
		b[i+1]=s[i]-'0';
		c[i]=i;
		if(b[i])sum++;
		if(b[i]!=1)tsf=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	if(sum<m)
	{
		cout<<0;
		ex;
	}
	if(m==n)
	{
		if(sum==n)
		{
			cout<<1;
		}
		else cout<<0;
		ex;
	}
	if(tsf)
	{
		int t=1;
		for(int i=1;i<=n;i++)
		{
			t*=i;
			t%=mod;
			
		}
		cout<<t;
		ex;
	}
	do{
		
		int sum=0,tsum=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i]==0)tsum++;
			if(b[i]==1)
			{
				if(tsum<a[c[i]])
				{
					sum++;
				}
				else tsum++;
			}
		}
		
		if(sum>=m)
		{
			ans++;
			//cout<<sum<<endl;
		}
		
//		for(int i=1;i<=n;i++)
//		{
//			cout<<c[i]<<' '; 
//		}
//		cout<<endl;
		ans=ans%mod;
	}while(next_permutation(c+1,c+1+n));
	cout<<ans;
	sinzo code;
}
/*
4 3
1011
1 2 2 2


10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
/**
 * 
 * 请输入文本
 * luogu sinzo 873466
 * 
 * 
 * 咕咕咕180=100+40+(0~100)+(40~100)
 * 嘤嘤嘤，没有S1=了qaq
 * # 技不如人，受着！
 * 
 * freopne("emplyo.in","r","stdin");
 * freoepn("empoly.out","w","stdout");
 * frepoen("emlpoy.in",r,stdin);
 * froepen("epmloy.out",w,stdout);
 * feropen(meploy.in,"r",stdin);
 * rfeopen(employ.out,"w",stdout);
 * #include<windows.h>
 * while(1)
 * 
/*/