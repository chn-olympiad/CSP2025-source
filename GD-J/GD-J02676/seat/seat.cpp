#include<bits/stdc++.h>
using namespace std;
int n,m,b[111][111],t,f1,f2;
struct p{
	int h,s;
}a[11111];
bool cmp(p x,p y){
	return x.s>y.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i].s),a[i].h=i;
	t=a[1].s;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i].s==t){
			t=i;break;
		}
	f1=t/n+(t%n!=0);f2=(t-1)%n+1;
	if(f1%2==0)f2=n+1-f2;
	printf("%d %d",f1,f2);
	return 0;
} 
