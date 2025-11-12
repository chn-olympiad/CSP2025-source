#include <bits/stdc++.h>
using namespace std;
int n,m,cnt=0,c=1,r=1,l=0;
int s[105],a[105],xr=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;(i<=n*m)&& (scanf("%d",&s[i])!=-1);i++){
		cnt++;
	}
	xr=s[1];
	sort(s+1,s+cnt+1);
	for(int i=1,j=cnt;i<=cnt;j--,i++){
		a[i]=s[j];
	}
	for(int i=1;i<=cnt;i++){
		if(a[i]==xr){
			c=(i-1)/n+1;
			l=i%n;
			if(l==0){
				l=n;
			}
			if(c%2==0){
				r=n-l+1;
			}
			else{
				r=l;
			}
			printf("%d %d",c,r);
			break;
		}
	}
	
	
	return 0;
}
