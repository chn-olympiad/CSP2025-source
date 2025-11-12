#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m,a;
int cnt=1;
// I Love Nahida Forever!!!
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&a);
	for(int i=1;i<n*m;i++){
		int os; // other score
		scanf("%d",&os);
		if(os>a)cnt++;
	}
	int h=0,l=cnt/n;
	if(cnt%n!=0)l++;
	h=cnt-(l-1)*n;
	if(l%2==0){
		h=n-h+1;
	}
	printf("%d %d",l,h);
	return 0;
}
//freopen("seat.in","r",stdin);
//freopen("seat.out","w",stdout);
//Welcome
// I Love Nahida Forever!!!
// I Love Nahida Forever!!!
// I Love Nahida Forever!!!
// I Love Nahida Forever!!!
// I Love Nahida Forever!!!

// Im hangxiaopa
