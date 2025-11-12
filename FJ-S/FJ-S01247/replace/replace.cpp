#include<bits/stdc++.h>
using namespace std;
int n,q;
char p[10001][2][40100];
char t1[20100],t2[20100];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i][0]>>p[i][1];
	}
	while(q--)
	{
		cin>>t1>>t2;
		int l1=strlen(t1),l2=strlen(t2),summ=0;
		if(l1!=l2) cout<<0<<'\n';
		else
		{
			for(int i=1;i<=n;i++)
			{
				int k=0,l3=strlen(p[i][0]);
				for(int j=0;j<l2;j++)
				{
					if(t1[j]!=p[i][0][k]) k=0;
					else k++;
					if(k==l3)
					{
						char m[20100];
						int w=0;
						for(int o=0;o<l2;o++) m[o]=t1[o];
						for(int o=j-k+1;o<=j;o++)
						{
							m[o]=p[i][1][w++];
						}
						bool pd=1;
						for(int o=0;o<l2;o++)
						{
							if(m[o]!=t2[o]) pd=0;
						}
						if(pd) summ++;
						k=0;
					}
				}
			}
			cout<<summ<<'\n';
		}
	}
	return 0;
}
/*
4 2
abc cba
ert tcb
tcb ert
rtrt rtrt
00erttcb987 00tcbert987
abcabc cbaabc
*/
