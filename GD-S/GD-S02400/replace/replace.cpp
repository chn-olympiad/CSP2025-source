#include<bits/stdc++.h>
using namespace std;
int t;
long long sum;
string a[100005],b[100005];
struct node
{
	int number=0;
	string a[100005],b[100005];
}fk[50];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		fk[a[i][0]-'a'].a[++fk[a[i][0]-'a'].number]=a[i];
		fk[a[i][0]-'a'].b[fk[a[i][0]-'a'].number]=b[i];
	}
	for(int i=1;i<=q;i++)
	{
		string z1,z2;
		cin>>z1>>z2;
		int t=z1.size();
		int sum=0;
		int m=0,r=t-1;
		while(1)
		{
			if(z1[m]!=z2[m])
				break;
			m++;
		}
		while(1)
		{
			if(z1[r]!=z2[r])
				break;
			r--;
		}
//		for(int j=m;j<=r;j++)
//		{
//			cout<<z1[j];
//		}
//		cout<<' ';
//		for(int j=m;j<=r;j++)
//		{
//			cout<<z2[j];
//		}
		//m,r
		
		int u=r-m;
		string mm=z1;
		for(int j=0;j<t;j++)
		{
			char sb=z1[j];
			string nn=mm;
			swap(nn,z1);
			int num=fk[sb-'a'].number;
//			cout<<num<<endl;
			for(int k=1;k<=num;k++)
			{
//				cout<<fk[sb-'a'].a[k]<<endl;
				if(fk[sb-'a'].a[k].size()<u)
					continue;
				for(int l=0;l<fk[sb-'a'].a[k].size();l++)
				{
					z1[j+l]=fk[sb-'a'].b[k][l];
				}
//				cout<<z1<<' '<<z2;
								if(z1==z2)
					sum++;
			}
			swap(nn,z1);
		}
		printf("%d\n",sum);
	}
	return 0;
} 
