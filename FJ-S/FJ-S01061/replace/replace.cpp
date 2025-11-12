#include<bits/stdc++.h>
using namespace std;

int read(){int x=0,f=1;char c=getchar();while(c<48 || c>57){if(c=='-'){f=-1;}c=getchar();}while(c>=48 && c<=57){x=(x<<1)+(x<<3)+(c^48);c=getchar();}return x*f;}
void write(int x){if(x<0){x=-x;putchar('-');}if(x>9){write(x/10);}putchar((x%10)^48);}
/*


*/
const int N=2e5+10;
string s1[N][3],s2[N][3];
int n,q,ans;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;++i) cin>>s1[i][1]>>s1[i][2];
	for(int i=1;i<=q;++i)
	{
		ans=0;
		cin>>s2[i][1]>>s2[i][2];
		for(int j=1;j<=n;++j)
		{
			for(int k=0;k<s2[i][1].size()-s1[j][1].size()+1;++k)
			{
				int flag=1;
				for(int len=0;len<s1[j][1].size();++len)
				{
					if(s2[i][1][k+len]!=s1[j][1][len] || s2[i][2][k+len]!=s1[j][2][len])
					{
						flag=0;break;
					}
				}
				if(!flag) continue;
				ans++;
			}
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}

