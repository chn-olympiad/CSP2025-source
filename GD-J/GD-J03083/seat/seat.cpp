#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,l[105]={},a,b,x,y;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n*m;i++){
		scanf("%d",&l[i]);
	}
	a=l[0];
	sort(l,l+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(l[i]==a){
			b=i+1;
			break;
		}
	}
	if(b%n==0){
		x=b/n;
	}
	else{
		x=b/n+1;
	}
	if(x%2==0){
		if(b%n==0){
			y=1;
		}
		else{
			y=n+1-b%n;
		}
	}
	else{
		if(b%n==0){
			y=n;
		}
		else{
			y=b%n;
		}
	}
	printf("%d %d",x,y);
	return 0;
}
