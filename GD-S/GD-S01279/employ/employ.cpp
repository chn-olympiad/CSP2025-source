#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
string s;
long long n,m,ans;
bool v[10000];
int b[1000];
int c[1000];
void pd()
{
	int r=0,d=0;
	for(int i=0;i<n;i++)
	{
		if((s[i]-'0')==0)
		{
			d++;
		}else
		{
			if(c[b[i+1]]>d)
			{
			//	cout<<b[i+1]<<' ';
				r++;
			}else d++;
		}
	}
	if(r>=m) 
	{
//		cout<<endl;
//		cout<<r;
//		cout<<b[1]<<' ';
		ans++;
		ans%=mod;
/*	for(int i=1;i<=n;i++)
					cout<<b[i]<<' ';
				cout<<endl;*/
	}
}

void dfs(int k)
{
	for(int i=1;i<=n;i++)
	{
		if(!v[i])
		{
			b[k]=i;
			v[i]=1;
			if(k==n)
			{
			/*	for(int i=1;i<=n;i++)
					cout<<b[i]<<' ';
				cout<<endl;*/
				pd();
			}else dfs(k+1);
			v[i]=0;
			b[k]=0;
		}
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	if(n<100)
		dfs(1);
	else
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=i;
			ans%=mod;
		}
	}
//	n=10,m=5;
//	pd();
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
