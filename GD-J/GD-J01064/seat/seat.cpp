#include<bits/stdc++.h>
using namespace std;

int a[200];

bool cmp(const int &x,const int &y){ return x>y; }

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int l=n*m;
	for(int i=1;i<=l;i++)
		cin>>a[i];
	int r=a[1],s=0;
	sort(a+1,a+l+1,cmp);
	for(int i=1;i<=l;i++)
		if(a[i]==r)
		{
			s=i;
			break;
		}
	int k=s/n,p=s%n;//s/n=k...p
	if(p==0)
		cout<<k;
	else
		cout<<k+1;
	cout<<' ';
	if(k%2==1 && p!=0)
		cout<<n-p+1;
	else if(k%2==1 && p==0)
		cout<<n;
	else if(k%2==0 && p!=0)
		cout<<p;
	else
		cout<<1;
	return 0;
}

