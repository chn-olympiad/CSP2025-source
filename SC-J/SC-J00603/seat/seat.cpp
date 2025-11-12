#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,k,a[N],st;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);k=n*m;
	for(int i=1;i<=k;i++)
		scanf("%d",&a[i]);
	st=a[1];
	sort(a+1,a+k+1);
	st=lower_bound(a+1,a+k+1,st)-a;
	st=k-st+1;
	int ans1=(st-1)/n+1;
	printf("%d ",ans1);
	int now=st-((st-1)/n)*n;
	printf("%d\n",(ans1&1)?now:n-now+1);
	return 0;
}