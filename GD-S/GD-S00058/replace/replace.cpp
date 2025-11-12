#include<bits/stdc++.h>
using namespace std;
long long n,q,num;
struct node{
	string k1,k2;
};
node a[200005];
string s1,s2,s,s3;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].k1>>a[i].k2;
	}
	while(q>0)
	{
		q--;
		cin>>s1>>s2;
		num=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j+a[i].k1.size()<=s1.size();j++)
			{
				s3="";
				for(int k=j;k<j+a[i].k1.size();k++)
				{
					s3+=s1[k];
				}
				if(s3==a[i].k1)
				{
					s="";
					for(int k=0;k<j;k++)
					{
						s+=s1[k];
					}
					s+=a[i].k2;
					for(int k=j+a[i].k1.size();k<s1.size();k++)
					{
						s+=s1[k];
					}
					if(s==s2)
					{
						num++;
					}
				}
			}
		}
		cout<<num<<endl;
	}
	return 0;
}
