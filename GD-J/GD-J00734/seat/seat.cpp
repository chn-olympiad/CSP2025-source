#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,sun,cnt,c;
int a[110];
int t;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
 	cin>>n>>m;
	cnt=m*n;
	for(int i=1;i<=cnt;i++){
		cin>>a[i];
		
	}
	sun=a[1];
	sort(a+1,a+1+cnt,cmp); 
	for(int i=1;i<=cnt;i++){
		if(a[i]==sun) t=i;
	}
	
	if(t%n) y=t/n+1;
	else y=t/n;
	c=y%2;
	if(c) x=t-((y-1)*n)	;
	else x=n-(t-((y-1)*n))+1;
		
	printf("%d %d",y,x);
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
