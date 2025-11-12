#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a[105];
int main(){
	freopen("seat.in""r",stdin)
	freopen("seat.out""w",stdout)
	int n,m;
	cin >>n>>m;
	int b=1;
	int c,d;
	c=n;
	d=m;
	for(int i=1;i<=c*d-1;i++)
	{
		cin >>a[i];	
	}
	for(int j=1;j<=c*d;j++){
	
		if(a[0]<a[j])
		{
			b=b+1;
		}
	}
	if(n<=1)
	{
		cout <<n<<" "<<b;
	}
	if(m<=1)
	{
		cout <<b<<" "<<m;
	}
	
	return 0;
}

