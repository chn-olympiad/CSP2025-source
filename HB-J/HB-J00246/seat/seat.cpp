#include <bits/stdc++.h>
using namespace std;
int n,m,r,a[105],h,l;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int rt=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==rt){
			r=i;
			break;
		}
	}
	l=r/n;
	if(r%n>0){
		l+=1;
	}
	cout<<l<<" ";
	if(l%2==1)
	{
		if(r%n==0){
			cout<<n;
		}
		else{
			cout<<r%n;
		}
	}
	else
	{
		if(r%n==0){
			cout<<0;
		}
		else {
			cout<<n-(r%n)+1;
		}
	}
	return 0;
}
