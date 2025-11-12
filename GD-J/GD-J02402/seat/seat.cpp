#include <bits/stdc++.h> 
using namespace std;
int a[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int x=a[1];
	if(x==0){
		if(m%2==0)printf("%d 1",m)
		else printf("%d %d",m,n);
		return 0;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			if((i/n)%2==0){
				if(i%n==0)
					printf("%d 1",i/n);
				else
					printf("%d %d",i/n+1,i%n);
			}
			else{
				if(i%n==0)
					printf("%d 1",i/n);
				else printf("%d %d",i/n+1,n-i%n+1);
			}
			return 0;
		}
	}
	return 0;
}
