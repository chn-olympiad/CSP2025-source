#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],s,k,x,y,l;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) {
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++) {
		if(a[i]==s) {
			l=i;
			break;
		}
	}
	for(int j=1;j<=m;j++) {
		if(j%2==1)
		{
			for(int i=1;i<=n;i++) {
				k++;
				if(k==l) {
					x=i,y=j;
					break;
				}
			}
		}
		else 
		{
			for(int i=n;i>=1;i--) {
				k++;
				if(k==l) {
					x=i,y=j;
					break;
				}
			}
		}
	}
	printf("%d %d",y,x);
	return 0;
}
