#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,t,p;
struct sct{int x,y;}a[N];
bool cmp(sct A,sct B){return A.x>B.x;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i].x),a[i].y=i; 
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)if(a[i].y==1){t=i;break;}
	p=t%n;t/=n;
	if(p)t++;
	else p=n;
	printf("%d ",t);
	if(t%2)printf("%d",p);
	else printf("%d",n-p+1);
	return 0;
}