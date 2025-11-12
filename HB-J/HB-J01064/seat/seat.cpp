#include<bits/stdc++.h>
using namespace std;
int m,n,a[105],r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m*n;i++){
		if(a[i]==r){
			if(((i-1)/n+1)%2==1)
			printf("%d %d",(i-1)/n+1,(i-1)%n+1);
			else
			printf("%d %d",(i-1)/n+1,n-((i-1)%n+1)+1);
		}
	}
	return 0;
}
