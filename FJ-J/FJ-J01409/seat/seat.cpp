#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int gd[1000];
	int nn,mm,x,tt=0;
	cin>>m>>n;
	for(int i=0;i<=n*m-1;i++)
	{
		cin>>gd[i];
		if(i==0) x=gd[i];
		else if(gd[i]>x) tt++;
	}
	tt++;
	
	if(tt%n>0) mm=(tt/n)+1;
	else mm=tt/n;
	
	if(mm%2) nn=tt%n;
	else nn=n-tt%n+1;

	if(nn==0) nn=n;
	
	cout<<mm<<" "<<nn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
