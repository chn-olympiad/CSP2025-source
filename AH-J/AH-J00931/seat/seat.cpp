#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m,a[105];
bool cmp(int x,int y){
	return x>y;
}
int xs(int a,int b){
	if(a%b==0){
		return a/b;
	}
	else{
		return a/b+1;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int p=a[1];
	sort(a+1,a+1+(n*m),cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==p){
			int v=i;
			int k=xs(v,n);
			int wi=v%n;
			if(k%2==0){
				if(wi==0){printf("%d %d",k,1);}
				else{printf("%d %d",k,n-wi+1);}
			}
			else{
				if(wi==0){printf("%d %d",k,n);}
				else{printf("%d %d",k,wi);}
			}
			break;
		}
	}
	return 0;
}
