#include<bits/stdc++.h>
using namespace std;
int a[200];
bool cmp(int c,int d){
	return c>d;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int r=a[1],h=n*m;
	sort(a+1,a+1+h,cmp);
	for(int i=1;i<=h;i++){
		if(r==a[i]){
			int l=(i+n-1)/n,hs;
			if(l%2==1){
				hs=i%n;
		        if(hs==0){
					hs=n;
				}
			}
			else{
				hs=n-i%n+1;
				if(hs==n+1) hs=1;
			}
			printf("%d %d",l,hs);
			return 0;
		}
	}
	return 0;
}

