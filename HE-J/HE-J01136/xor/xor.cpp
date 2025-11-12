#include<bits/stdc++.h>
using namespace std;
string a[5010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum=0;
	string b="0";
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int l,j=0;
		cin>>l;
		if(l==0)
		{
			a[i]="0";
		}
		while(l)
		{
//			cout<<l%2;
			a[i]+=char(l%2+'0');
			l/=2;
		}
//		cout<<a[i]<<endl;
		reverse(a[i].begin(),a[i].end());
	}
	for(int l=1;l<=n;l++)
	{
		for(int r=l+1;r<=n;r++)
		{
			b="0";
			int num=0;
			for(int i=l;i<=r;i++)
			{
				string c="";
				for(int j=0;j<max(a[i].size(),b.size());j++)
				{
					if(a[i][j]!=b[j])
					{
						c+='1';
					}
					else
					{
						c+='0';
					}
				}
				b=c;
				reverse(b.begin(),b.end());
			}
			reverse(b.begin(),b.end());
			for(int i=0;i<b.size();i++)
			{
				num+=pow(2,i)*(b[i]-'0');
			}
			if(k==num)
				sum++;
		}
	}
	cout<<sum;
	return 0;
}
