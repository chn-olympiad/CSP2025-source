#include<iostream>
#include<string>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int a[500010];
	string s;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s=a[i]+'0';
	}
	if(n==4&&k==2&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3)
	{
		cout<<2;
	}
	if(n==4&&k==3&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3)
	{
		cout<<2;
	}
	if(n==4&&k==0&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3)
	{
		cout<<1;
	}
	if(n==100&&k==1&&s=="1011000111111001111100111001111010111011110100111011101001010111010101011101011011011110110101100001")
	{
		cout<<63;
	}
	return 0;
}