#include<bits/stdc++.h>
using namespace std;
int n,m,a,x,cnt=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a;
    for(int i=1;i<(n*m);i++)
    {
    	cin>>x;
    	if(a<x)
    	cnt++;
	}
	cnt++;
	int cnt2=cnt/n,cnt3=cnt%n;
	if(cnt3)
		cnt2++;
	else
		cnt3=n;
	if(cnt2%2==0)
	{
		cnt3=n-cnt3+1;	
	}
	cout<<cnt2<<" "<<cnt3;
	return 0;
}
