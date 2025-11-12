#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2005;
char t1[50006],t2[50006];
int boad[N],B[N],n,q;
char s[N][3][50006];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (int i=1;i<=n;i++)
	{
		cin >> s[i][1]+1 >> s[i][2]+1;
		B[i]=strlen(s[i][1]+1);
	}
	while (q--)
	{
		cin >> t1+1 >> t2+1;
		int l=strlen(t1+1);
		int ans=0;
		for (int i=1;i<=n;i++)
		{
			memset(boad,0,sizeof(boad));
			for (int j=1,k=0;j<=B[i];j++)
			{
				while(k>0&&s[i][1][k+1]!=s[i][1][j])
				{
					k=boad[k];
					//cout << 1;
				}
				if (s[i][1][k+1]==s[i][1][j]) k++;
				boad[j]=k;
			}
			for (int j=1,k=0;j<=l;j++)
			{
				while(k>0&&s[i][1][k+1]!=t1[j])
				{
					k=boad[k];
				}
				if (s[i][1][k+1]==t1[j]) k++;
				if (k==B[i]) 
				{
					//if (check())
					//{
					//	ans++;
					//}
					k=boad[k];
				}
			}
			for (int j=1;j<=B[i];j++)
			{
				//cout << boad[j] << " ";
			}
			cout << "\n";
		}
		cout << "\n\n\n";
		//cout << ans;
		cout << (rand()<<15|rand()) << "\n";
	}
	return 0;
}
