#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],cnt,d;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(i==1)cnt=a[i];
		else if(a[i]>cnt)d++;
	}
	int ans=d/n+1,sum=d%n+1;
	if(ans%2==0)
		sum=n-sum+1;
	printf("%d %d",ans,sum);
	return 0;
}
