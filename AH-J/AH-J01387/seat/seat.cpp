#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int g=n*m;
	for(int i=1;i<=g;i++){
		scanf("%d",&a[i]);
	}
	int h=a[1],k;
	sort(a+1,a+g+1,cmp);
	for(int i=1;i<=g;i++){
		if(a[i]==h){
			k=i;
			break;
		}
	}
	int l=k/n,r=k%n;
	if(r==0){
		if(l%2==1){
			printf("%d %d",l,m);
		}
		else printf("%d %d",l,1);
	}
	else{
		l+=1;
		if(l%2==1){
			printf("%d %d",l,r);	
		}
		else printf("%d %d",l,(m-r+1));
	}
	return 0;
}
