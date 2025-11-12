#include<bits/stdc++.h>
using namespace std;
int grade(int x,int y)
{
	if(x>y) return x;
	if(y>x)	return y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,m;
	int num[n*m];
	cin>>n>>m>>num[n*m];
	cout<<n+1<<m+1;
	
	return 0;
}
