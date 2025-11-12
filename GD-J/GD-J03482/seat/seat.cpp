#include<bits/stdc++.h>
using namespace std;
int x,y,n,k,l=1,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d %d",&x,&y,&n);
	for(int i=2,p;i<=x*y;i++){
		scanf("%d",&p);
		if(p>n)l++;
	}
	k=l/y+1;
	if(k%2==1)r=l%y;
	else r=y-l%y+1;
	printf("%d %d",k,r);
	return 0;
}
