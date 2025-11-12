#include<bits/stdc++.h>
#define mod 998244353
#define P 107
using namespace std;
int n,q;
string s[200005][2];
int hah[200005][2];
int pw[5000005];
string que[200005][2];
vector<int>h[2];
int geth(int l,int r,int opt)
{
	return ((h[opt][r]-1ll*h[opt][l-1]*pw[r-l+1]%mod)%mod+mod)%mod;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	pw[0]=1;
	for(int i=1;i<=5000005;i++)pw[i]=1ll*pw[i-1]*P%mod;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++)cin>>que[i][0]>>que[i][1];
	for(int i=1;i<=n;i++)
	{
		int l=s[i][0].length();
		for(int j=0;j<l;j++)hah[i][0]=(1ll*hah[i][0]*P%mod+s[i][0][j]-'a'+1)%mod;
		for(int j=0;j<l;j++)hah[i][1]=(1ll*hah[i][1]*P%mod+s[i][1][j]-'a'+1)%mod;
	}
	for(int i=1;i<=q;i++)
	{
		h[0].clear();
		h[1].clear();
		int l=que[i][0].length();
		if(l!=que[i][1].length())
		{
			printf("0\n");
			continue;
		}
		h[0].resize(l+1);
		h[1].resize(l+1);
		for(int j=0;j<l;j++)h[0][j+1]=(1ll*h[0][j]*P%mod+que[i][0][j]-'a'+1)%mod;
		for(int j=0;j<l;j++)h[1][j+1]=(1ll*h[1][j]*P%mod+que[i][1][j]-'a'+1)%mod;
//		printf("OPF %d %d\n",geth(2,2,0),h[0][2]);
		int res=0;
		for(int k=1;k<=n;k++)
		{
			for(int j=0;j<l;j++)
			{
				if(j!=0&&geth(1,j,0)!=geth(1,j,1))continue;
				int p=j+s[k][0].length()-1;
				if(p>=l)continue;
				if(geth(j+1,p+1,0)==hah[k][0]&&geth(j+1,p+1,1)==hah[k][1]&&(p+1==l||geth(p+2,l,0)==geth(p+2,l,1)))res++;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
