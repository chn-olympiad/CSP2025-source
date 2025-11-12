#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,ji,cnt,cnt2;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
int main() 
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	ji=n*m;
	for(int i=1;i<=ji;i++){
		scanf("%d",&a[i]);
	}
	cnt=a[1];
	sort(a+1,a+ji+1,cmp);
	for(int i=1;i<=ji;i++){
		if(a[i]==cnt){
			cnt2=i;
		}
	}
	if(cnt2%m==0){
		c=cnt2/m;
	}
	else c=cnt2/m+1;
	if(c%2==0){
		cnt2%=n;
		if(cnt2==0) r=1;
		else r=n+1-cnt2;
	}
	else{
		cnt2%=n;
		if(cnt2==0) r=n;	
		else r=cnt2;
	}
	printf("%d %d",c,r);
	return 0;
}
