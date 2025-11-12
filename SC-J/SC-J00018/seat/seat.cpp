#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;
int a[105];
int cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(i>1){
			if(a[i]>a[1]){
				cnt++;
			}
		}
	}
	if(cnt%n==0){
		c=cnt/n;
		r=c%2==0?1:n;
	}else{
		c=cnt/n+1;
		if(c%2==0){
			r=n-cnt%n+1;
		}else{
			r=cnt%n;
		}
	}
	printf("%d %d",c,r);
	return 0;
}