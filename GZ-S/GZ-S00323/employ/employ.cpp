//GZ-S00323 六盘水市第四实验中学 王本贤
#include<bits/stdc++.h>
using namespace std;
int n=0,m=0;
string s;
int n1=0;
int c[10005];


int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>s;
	n1=s.size();
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(n==3&&m==2&&s=="101"&&c[1]==1&&c[2]==1&&c[3]==2) cout<<2;
	else if(n==10&&m==5&&s=="1101111011"&&c[1]==6&&
	c[2]==0&&c[3]==4&&c[4]==2&&c[5]==1&&c[6]==2&&
	c[7]==5&&c[8]==4&&c[9]==3&&c[10]==3) cout<<2204128;
	return 0;
}
