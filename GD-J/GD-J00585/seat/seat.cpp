#include<iostream>
using namespace std;
int main()
{
	foropen("seat.in","r",stdin);
	foropen("seat.out","w",stdout);
	int n,m,chengji={};
	cin>>n>>m;
	cin>>chengji;
	for(chengji=0;chengji<=100;chengji++)
		for(int i=1;i<=n;i++)
			for(int j=m;j>=1;j--)
			{
				cout<<i<<j;
			}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
