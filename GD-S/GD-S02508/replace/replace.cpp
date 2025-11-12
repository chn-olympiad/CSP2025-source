#include<bits/stdc++.h>
using namespace std;
long long n,q,i1,i2,L,I1[300009],I2[300009],H1[300009],H2,l,r,Len[300009],flag,ans;
string s[300009][2],t[300009][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i)
	{
		cin>>s[i][0]>>s[i][1];
		L=s[i][0].size();
		i1=0;
		i2=L+1;
		while(i1<L&&s[i][0][i1]==s[i][1][i1])
		{
			++i1;
		}
		while(i2>1&&s[i][0][i2-2]==s[i][1][i2-2])
		{
			--i2;
		}
		I1[i]=i1;
		I2[i]=i2;
		Len[i]=L;
//		printf("%lld %lld %lld\n",I1[i],I2[i],Len[i]);
	}
	for(int i=1;i<=q;++i)
	{
		cin>>t[i][0]>>t[i][1];
		L=t[i][0].size();
		if(t[i][0].size()!=t[i][1].size())
		{
			cout<<0<<endl;
		}
		else
		{
			ans=0;
			i1=0;
			i2=L+1;
			while(i1<L&&t[i][0][i1]==t[i][1][i1])
			{
				++i1;
			}
			while(i2>1&&t[i][0][i2-2]==t[i][1][i2-2])
			{
				--i2;
			}
//			printf("%lld %lld\n",i1,i2);
			if(i1<i2)
			{
				for(int j=1;j<=n;++j)
				{
					l=i1-I1[j]+1;
					r=i2+(Len[j]-I2[j]);
					if(l>=1&&r<=L&&i2-i1+1==I2[j]-I1[j]+1)
					{
						flag=1;
//						printf("%lld %lld %lld\n",j,l,r);
						for(int k=l;k<=r;++k)
						{
							if(k-l>=Len[j])
							{
								cout<<s[j][0]<<' '<<s[j][1]<<' '<<t[i][0]<<' '<<t[i][1]<<endl;
								return 0;
							}
							if(s[j][0][k-l]!=t[i][0][k-1]||s[j][1][k-l]!=t[i][1][k-1])
							{
//								printf("%lld %lld %lld %d\n",j,l,r,k);
								flag=0;
								break;
							}
						}
						if(flag==1)
						{
							++ans;
						}
					}
				}
				cout<<ans<<endl;
			}
			else
			{
				cout<<0<<endl;
			}
		}
		
	}
	return 0;
}
/*
in:
5 5
a a
*/
