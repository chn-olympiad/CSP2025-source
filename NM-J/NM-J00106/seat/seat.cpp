#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a;
	cin>>n>>m;
	cout<<endl;
	int a1;
	cin>>a1;
	int x=0,y=0;
	int nums;
	for(int i=1;i<n*m;i++)
	{
		cin>>a;
		if(a>a1)
		{
			nums++;
		}
	}
	nums=nums++; 
	x=nums/m;
	if(x%2==0)
	{
		y=nums-nums%m;
	}
	else
	{
		y=m-nums+nums%m+1;
	}
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
