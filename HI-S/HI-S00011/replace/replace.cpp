#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int n,q;
struct {
	string s;
}a[3][N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=2;j++)
		{
			cin>>a[j][i].s;
		}
	}
	for(int i=1;i<=q;i++)
	{
		string s1,s2;
		int sum=0;
		cin>>s1>>s2;
		for(int k=1;k<=n;k++)
		{
			if(s1.find(a[1][k].s)==s2.find(a[2][k].s)&&s1.find(a[1][k].s)!=-1)
			{
				int si=a[1][k].s.size(),x=s1.find(a[1][k].s);
				string s3=s1;
				for(int j=x,l=0;l<si;l++,j++)
				{
					s3[j]=a[2][k].s[l];
				}
				if(s3==s2)
					sum++;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
} 
