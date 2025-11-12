#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout); 
    cin>>n>>m;
    int g=n*m;
	int print[2];
	int k=m%2;
	int s=m/2;
	if(k==0)
	{
		print[2]--;
	}
	else
		print[2]++;
	print[1]=s;
	cout<<print<<endl;
}
