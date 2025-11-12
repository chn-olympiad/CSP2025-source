#include<bits/stdc++.h>
using namespace std;
int h,s,l;
int n,re=0,k;
int b[1000005],a[1000005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>h>>s;
	n=h*s;
	for (int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	
    for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if(b[j]>re)
			{
				re=b[j];
				k=j;
			}	
		}
		if (re==b[1])
		{
			l=i;
		}
		a[i]=re;
		re=0;
		b[k]=0;
	}
	int q=l/h;
	int j=l-(s*q);
	cout<<j;
	if(q%2==0) {
		cout<<q+1<<" "<<j+1;
	}
	else {
		cout <<q<<" "<<s-j;
	}

	return 0;
}
