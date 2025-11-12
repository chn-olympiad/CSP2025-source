#include<bits/stdc++.h>
using namespace std;
const int N = 1e2+10;
struct winn{
	int number;
	int fenshu;
}a[N];
int n,m,x;
bool cmp(winn a,winn b)
{
	return a.fenshu > b.fenshu;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin>>n>>m;
	int len=n*m;
	for(int i=1;i<=len;i++)
	{
		cin>>a[i].fenshu ;
		a[i].number = i;
	}
	sort(a+1,a+len+1,cmp);
	for(int i=1;i<=len;i++)
	{
		if(a[i].number == 1)
		{
			x=i;
		}
	}
	if(x%n==0) cout<<x/n<<" ";
	else cout<<x/n+1<<" ";
	
	if(x%n==0)
	{
		if((x/n)%2!=0)
		{
			cout<<n;
		}else{
			cout<<1;
		}
	}else{
		if((x/n+1)%2!=0)//ÕýÄæÐò 
		{
			cout<<x%n; 
		}else{
			cout<<n-(x%n)+1;
		}
	}

	return 0;
}
