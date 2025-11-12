#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int aaa;
int a[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    if(1==n and 1==m){
		printf("1 1");
		return 0;
	}
	scanf("%d",&aaa);
	a[0]=aaa;
	for(int i=1;i<n*m;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n*m);
	for(int c=1,r=1,i=n*m-1;i>=0;i--){
		if(aaa==a[i]){
			printf("%d %d",c,r);
			return 0;
		}
		if(c%2!=0 and n==r){
			c++;
			continue;
		}
		if(c%2==0 and 1==r){
			c++;
			continue;
		}
		if(c%2==0){
			r--;
			continue;
		}else{
			r++;
			continue;
		}
	}
}
