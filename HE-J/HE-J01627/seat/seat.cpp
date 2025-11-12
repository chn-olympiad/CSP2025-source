#include<bits/stdc++.h>
using namespace std;
int s[105],n,m,r,x,y;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m*n;i++){
		cin>>s[i];
	}r=s[1];
	sort(s+1,s+m*n+1,cmp);
	for(int i=1;i<=m*n;i++){
		if(r==s[i]){
			x=i%n;
			y=i/n+1;
			if(x==0){
				x=n;
				y--;
			}
			if(y%2==0){
				x=n-x+1;
			}
			break;
		}
	}
	printf("%d %d",y,x);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
