#include <bits/stdc++.h>
using namespace std;
int b[105][105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[1005],cnt,ans;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	cnt=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==cnt){
			ans=i;
			break;
		}
	}
	cnt=ans/m;
	if(ans%m==0){
		if(cnt%2==0){
			printf("%d %d",cnt,1);
		}
		if(cnt%2!=0){
			printf("%d %d",cnt,m);
		}
	}
	if(ans%m!=0){
		if((cnt+1)%2!=0){
			printf("%d %d",cnt+1,ans%m);
		}
		if((cnt+1)%2==0){
			printf("%d %d",cnt+1,ans%m+n/2);
		}
	}
	return 0;
}