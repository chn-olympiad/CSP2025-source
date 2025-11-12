#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],b;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin),freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n*m;i++)scanf("%d",&a[i]);
	b=a[0],sort(a,a+n*m,cmp);
	for(int i=0,x=1,y=1,op=1;i<n*m;i++){
		if(a[i]==b){
			printf("%d %d\n",x,y);
			fclose(stdin),fclose(stdout);
			return 0;
		}
		y+=op;
		if(y==n+1)y=n,x++,op=-1;
		else if(y==0)y=1,x++,op=1;
	}
	fclose(stdin),fclose(stdout);
	return 0;
}