#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[105],x;
int cmp(int a,int b){
	return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    ans=n*m;
    for(int i=1;i<=ans;i++)scanf("%d",&a[i]);
    x=a[1];
    sort(a+1,a+1+ans,cmp);
    int l=1,r=ans;
    while(l<r){
		int mid=(l+r)/2;
		if(a[mid]>x)l=mid+1;
		else r=mid;
	}
	int dx,dy;
	dx=(l-1)/n+1;
	if(dx%2==0){
		if(l%n==0)dy=1;
		else dy=n+1-l%n;
		}
	else if(l%n==0)dy=n;
	     else dy=l%n;
	cout<<dx<<' '<<dy;
    return 0;
   }
