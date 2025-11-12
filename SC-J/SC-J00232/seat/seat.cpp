#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,r,tot=0,ansn,ansm;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1);
	while(a[n*m-tot]!=r) tot++;
/*	for(int i=1;i<=n*m;i++)
	{
		cout<<a[i]<<" ";
	}*/
	tot++;
//	cout<<tot<<" ";
	if(tot%n==0) ansn=tot/n;
	else ansn=tot/n+1;//列 
	if(ansn%2==0) ansm=(n+1-tot%n)%n;//偶数列时 
	else{//奇数列时 
		if(tot%n!=0) ansm=tot%n;
		else ansm=n;
	}
	cout<<ansn<<" "<<ansm;
	return 0;
}
