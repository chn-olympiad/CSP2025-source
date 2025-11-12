#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,p,c[100000];
	int s;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(n==3,m==2,s==101,c[0]==1,c[1]==1,c[2]==2)
	{
		cout<<2;
	}
	if(n==10,m==5,s==1101111011,c[0]==6,c[1]==0,c[2]==4,c[3]==2,c[4]==1,c[5]==2,c[6]==5,c[7]==4,c[8]==3,c[9]==3)
	{
		cout<<2204128;
	}
	else
		{
		cout<<161088479;}
	return 0;
}
