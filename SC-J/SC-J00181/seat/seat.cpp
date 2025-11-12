#include<iostream>
#include<algorithm>
using namespace std;
const int N=20;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int len=n*m;
	for(int i=1;i<=len;i++)scanf("%d",&a[i]);
//	for(int i=1;i<=len;i++)printf("%d ",a[i]);
//	puts("");
	int tar=a[1];
	sort(a+1,a+len+1,cmp);
//	for(int i=1;i<=len;i++)printf("%d ",a[i]);
	int c=0,r=0;
	for(int i=1;i<=len;i++){
		if(a[i]==tar){
//			printf("%d %d\n",i,i/n);
			if(i%n==0){
				if((i/n)%2==0){
					c=i/n,r=1;
				}else{
					c=i/n,r=n;
				}
			}else{
				if((i/n)%2==0){
					c=(i+n)/n,r=i%n;
				}else{
					c=(i+n)/n,r=n-i%n+1;
				}
			}
		}
	}
	printf("%d %d",c,r);
	return 0;
}