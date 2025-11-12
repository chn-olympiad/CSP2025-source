#include<bits/stdc++.h>
using namespace std;
const int N=214514;
int n,q;
string s1[N],s2[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		int ret=0;
		for(int p=1;p<=n;p++)
		{
//			cout<<"p="<<p<<endl;
			int s1len=s1[p].length();
			string tt1=t1,tt2=t2;
			bool once=false;
			for(int i=0;i+s1len<=tt1.length();i++)
			{
				bool same=true;
				for(int j=i;j<i+s1len;j++)
				{
					if(tt1[j]!=s1[p][j-i])
					{
						same=false;
					}
				}
				if(same&&(once==false))
				{
					once=true;
//					cout<<"replacing\n";
					for(int j=i;j<i+s1len;j++)
					{
						tt1[j]=s2[p][j-i];
					}
				}
			}
//			cout<<tt1<<' '<<tt2<<endl;
			if(tt1==tt2&&once)
			{
				ret++;
			}
		}
		cout<<ret<<endl;
	}
	fclose(stdin);
	fclose(stdout);
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
*/