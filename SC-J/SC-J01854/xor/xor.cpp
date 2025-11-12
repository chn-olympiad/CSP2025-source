#include<bits/stdc++.h>
using namespace std;
inline void read(int &a)
{
	int s=0,w=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')
		{
			w=-1;
		}
		ch=getchar();
	}
	while(ch<='9'&&ch>='0')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	a=s*w;
} 

void write(int a)
{
	if(a<0)
	{
		a=-a;
	}
	if(a>9)
	{
		write(a/10);
	}
	putchar(a%10+'0');
}
struct node{
	int l,r;
};
int n,k;
int s[500005];
int dp[500005];
int w[500005];
queue<node> q;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	read(n);
	read(k);
	s[0]=0;
	//int t=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		read(x);
		s[i]=s[i-1]^x;
		w[i]=-1;
		for(int j=i-1;j>=0;j--)
		{
			if((s[i]^s[j])==k)
			{
				w[i]=j+1;
				//t++;
				//cout<<j+1<<' '<<i<<' '<<t<<endl;
				break;
			}
		}
	}
	//cout<<'*';
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		if(w[i]!=-1)
			dp[i]=max(dp[i-1],dp[w[i]-1]+1);
		else{
			dp[i]=dp[i-1];
		}
		//cout<<w[i]<<' '<<i<<' '<<dp[i]<<endl;
	}
	write(dp[n]);
	
	
}