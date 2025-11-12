#include<bits/stdc++.h>
using namespace std;
int a[101];
int cmp(int a,int b){
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int c,r;
	int x;
	cin>>n>>m;
	cin>>x;
	a[1]=x;
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n*m,cmp+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			if(i%n==0){
				c=i/n;
				if(c%2==0){
					r=1;
				}else{
					r=m;
				}
			}else{
				c=i/n+1;
				if(c%2==0){
					r=m+1-i%n;
				}else{
					r=i%n;
				}
			}
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
