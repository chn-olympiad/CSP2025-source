#include<bits/stdc++.h>
using namespace std;

int a[500];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int t=a[1];
	sort(a+1,a+n*m+1);
	int c=0,r=0;
	for(int i=n*m;i>=1;i--){
		int x=i/n;
		int y=i%n;
		if(y==0){
			c++;
		}
		if(c%2){
			r=(n+1-y)%n;
			if(r==0) r=n;
		}
		else{
			r=y;
			if(r==0) r=n;
		}
		if(a[i]==t){
			printf("%d %d",c,r);
			return 0;
		}
	}
	return 0;
}