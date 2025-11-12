#include<iostream>
#include<string>
using namespace std;
long long n,q,len[100005];
string s1[100005],s2[100005],q1,q2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		len[i]=s1[i].size();
	}
	for(int i=1;i<=q;i++)
	{
		cin>>q1>>q2;
		long long cnt=0;
		for(int j=0;j<q1.size();j++)
		{
			for(int k=1;k<=n;k++)
			{
				long long c=0;
				string s=q1;
				for(int m=j;m<=j+len[k];m++)
				{
					if(q1[m]==s1[k][c])s[m]=s2[k][c];
					else break;
					c++;
				}
				if(s==q2)cnt++;
			}
		}
		cout<<cnt<<endl;
	}	
	return 0;
}
