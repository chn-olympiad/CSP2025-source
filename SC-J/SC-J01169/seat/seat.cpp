#include<iostream>
using namespace std;
int n,m,a,b=1;
int f1[15],f2[15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d\n%d",&n,&m,&a);
	f1[0]=n,f1[1]=n;
	f2[0]=1,f2[1]=1;
	for(int i=2;i<n;i++) f1[i]=f1[i-1]-1;
	for(int i=2;i<n;i++) f2[i]=f2[i-1]+1;
	for(int i=1;i<n*m;i++){
		int x;
		scanf("%d",&x);
		if(x>a) b++;
	}
	if(b%n==0) printf("%d ",b/n);
	else printf("%d ",b/n+1);
	if(b%2==0) printf("%d",f1[b%n]);
	else printf("%d",f2[b%n]);
	return 0;
}