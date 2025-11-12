#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],c,r;
int main(){
	freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int nm=n*m;
	for(int i=1;i<=nm;i++){
		scanf("%d",&a[i]);
	}
	int x=a[1],y;//·ÖÊý 
	sort(a+1,a+nm+1,greater<>());
	for(int i=1;i<=nm;i++){
		if(a[i]==x){
			y=i;//ÅÅÃû 
			break;
		}
	}
	c=ceil(y*1.0/n);
	r=y%n;
	if(r==0) r=n;
	if(c%2==0) r=n+1-r;
	printf("%d %d",c,r);
	return 0;
}
