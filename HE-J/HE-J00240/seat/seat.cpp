#include<bits/stdc++.h>
using namespace std;
bool qwe (int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a1,w=0;
	double q1=0,q2=0,q3=0;
	cin>>n>>m;
	int a[n*m],b[n]={ };
	cin>>a[0];
	a1=a[0];
	for(int i=1;i<n*m;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n*m,qwe);
	while(a[w]!=a1)
	{
		w++;
	}
	w+=1;
	if(w%n!=0)
	{
		cout<<(int)w/n+1<<" ";
		q1=w;
		q2=n;
		q3=q1/q2;
		q3-=(int)q3;
		q2=1/n;
		q1=q3/q2;
		if(((int)w/n+1)%2!=0)
		{
			cout<<q1;
			return 0;
		}else
		{
			b[(int)q1-1]=11;
			q2=1;
			for(int i=n-1;i>=0;i--)
			{
				q2++;
				if(b[i]==11)
				{
					cout<<q2;
					return 0;
				}
			}
		}
	}else
	{
		cout<<w/n<<" ";
		if(w/n%2!=0)
		{
			cout<<n;
			return 0;
		}else
		{
			b[n-1]=11;
			q2=1;
			for(int i=n-1;i>=0;i--)
			{
				q2++;
				if(b[i]==11)
				{
					cout<<q2;
					return 0;
				}
			}
		}
		
	}
	return 0;
}
