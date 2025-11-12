#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[101],e=0,l,b,h,f;
	cin>>n;
	for(int c=1;c<=n;c++) cin>>a[c];
	sort(a+1,a+n+1);
	for(int c=1;c<=(1<<n)-1;c++)
	{
		l=c,h=0,f=0;
		for(int d=1;d<=n;d++,l/=2) if(l%2) h+=a[d],b=a[d],f++;
		if(f>2&&h>2*b) e++;
	}
	cout<<e;
	return 0;
}
