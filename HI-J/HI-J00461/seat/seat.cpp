#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,t=0,n=0,p=0,c[10001];
	cin>>a>>b;
	for(int i=1;i<=a*b;i++)
	cin>>c[i];
	t=c[1];
	sort(c,c+a*b);
	for(int i=1;i<=a*b;i++)
	{
		if(c[i]==t)
		t=a*b-i;
	}
	if(t>a)
	{
	n=t/a+t%a;
	}
	else
	n=1;
	p=t%a;
	if(n%2==0)
	cout<<n<<" "<<b-p+1;
	else cout<<n<<" "<<p;
 	return 0;
	fclose(stdin);
	fclose(stdout);
}
