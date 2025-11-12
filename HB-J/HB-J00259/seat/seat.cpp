#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	int a[101]={0};
	cin>>n>>m;
	cin>>a[0];
	int R=a[0];
	int k=0;
	
	for(int i=1;i<(n*m);i++)
	{
		cin>>a[i];
		if(a[i]>R)
		{
			k++;
		}
	}
	
	int l=floor(k/n);
	int h=k-(n*l);
	l++;
	
	if(l%2==1)
	{
		cout<<l<<" "<<(h+1);
	}
	else
	{
		cout<<l<<" "<<(n-h);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
