#include<bits/stdc++.h>
using namespace std;

int n,m,x;
int a[110];

bool cmp(int s1,int s2){
	return s1>s2;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=(n*m);i++)scanf("%d",&a[i]);
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=(n*m);i++){
		if(a[i]==x){
			if(((i-1)/n)%2==0){
				if(i%n==0)printf("%d %d",i/n,n);
				else printf("%d %d",i/n+1,i%n);
			}else{
				if(i%n==0)printf("%d %d",i/n,1);
				else printf("%d %d",i/n+1,n+1-i%n);
			}
		}
	}
	return 0;
}
