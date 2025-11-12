#include<bits/stdc++.h>
using namespace std;
int n,m,c,cnt=1,a;
//abs(a)<abs(o)
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	c=n*m;
	scanf("%d",&a);
	for(int x,i=1;i<c;i++){
		scanf("%d",&x);
		if(x>a)cnt++;
	}
//	printf("%d\n",cnt);
	int x=1,y=1;
	for(int i=2;i<=cnt;i++){
		if(x&1){
			y++;
			if(y==n+1){
				x++;
				y--;
			}
		}
		else{
			y--;
			if(y==0){
				x++;
				y++;
			}
		}
//		printf("%d %d\n",x,y);
	}
	printf("%d %d",x,y);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

