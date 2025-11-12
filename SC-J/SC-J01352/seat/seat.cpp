#include <bits/stdc++.h>
using namespace std;
int n,m,cnt,q=0;
struct node
{
	int a;
	int p;
}a[1000];

bool cmp(node a,node b)
{
	return a.a>b.a;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int x=n*m;
	for(int i=1;i<=x;i++)
	{
		cin>>a[i].a;
		a[i].p=i;
	}
	sort(a+1,a+x+1,cmp);
	for(int i=1;i<=x;i++)
    {
        if(a[i].p==1)
        {
            cnt=i-1;
            break;
        }
    }
    while(cnt-n>=0)
    {
    	q++;
    	cnt-=n;
	}
	if(q%2==0)
	{
		cout<<q+1<<" "<<cnt+1;
	}
	else
	{
		cout<<q+1<<" "<<n-cnt;
	}
	return 0;
}