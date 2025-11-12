#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x,sum,y;
int c,r;
double c1;
int cmp(int a,int b){
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	x=a[1];
	sum=n*m;
	sort(a+1,a+sum+1,cmp);
	for(int i=1;i<=sum;i++){
		if(a[i]==x){
			y=i;
			break;
		}
	}
	c=y/n;
	if(y%n!=0)c++;
	if(c%2==1){
		r=y-(c-1)*n;
	}
	else {
		r=n+1-(y-(c-1)*n);
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}