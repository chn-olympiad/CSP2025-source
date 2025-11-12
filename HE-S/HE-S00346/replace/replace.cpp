#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s[N][2],t1,t2;
int slen[N],tpr;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
		int cnt=0;
		while(s[i][0][cnt++]) slen[i]++;
	}
	for(int i=1;i<=q;i++)
	{
		tpr=0;
		int ans=0;
		cin>>t1>>t2;
		int cnt1=-1;
		while(t1[++cnt1])
		{
			if(t1[cnt1]!=t2[cnt1]) tpr++;
		}
		int cnt=-1;
		while(t1[++cnt])
		{
			for(int j=1;j<=n;j++)
			{
				int p=0;
				for(int k=0;k<slen[j];k++)
				{
					//cout<<s[j][0][k]<<' '<<t1[cnt]<<' '<<s[j][1][k]<<' '<<t2[cnt]<<' '<<tpr<<' '<<p<<endl;
					if(p==0&&s[j][0][k]==t1[cnt]&&s[j][1][k]==t2[cnt]) p=1;
					if(p==0&&s[j][0][k]==t1[cnt]&&s[j][1][k]==t2[cnt]&&t1[cnt]!=t2[cnt]) tpr--;
					if(p==1)
					{
						int cnt2=cnt;
						int tpr1=tpr;
						int j1=j,k1=k;
						while(s[j1][0][++k1]==t1[++cnt2]&&s[j1][1][k1]==t2[cnt2]&&tpr1>0)
						{
							//cout<<1<<' '<<s[j1][0][k1]<<' '<<t1[cnt2]<<' '<<s[j1][1][k1]<<' '<<t2[cnt2]<<' '<<tpr<<' '<<p<<endl;
							if(t1[cnt2]!=t2[cnt2]) tpr1--;
						}
						if(tpr1==0) ans++;
					}
				}
				if(p==1&&tpr==0) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
