#include<bits/stdc++.h>
const int N = 105;
int n,m,a[N],r,x = 1,y = 1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= n * m;i ++){
		scanf("%d",a + i);
		a[i] = -a[i];
	}
	r = a[1];
	std::sort(a + 1,a + n * m + 1);
	int f = 1;
	for(int i = 1;i <= m / 2;i ++){
		for(int j = 1;j <= n;j ++,f ++){ //Ç°°ëÈ¦ 
			if(a[f] == r){
				printf("%d %d\n",y,x);
				return 0;
			}
			x ++;
		}
		y ++;
		for(int j = 1;j <= n;j ++,f ++){ //ºó°ëÈ¦ 
			x --;
			if(a[f] == r){
				printf("%d %d\n",y,x);
				return 0;
			}
		}
		y ++; 
	}
	if(m & 1){
		for(int j = 1;j <= n;j ++,f ++){ //Ç°°ëÈ¦ 
			if(a[f] == r){
				printf("%d %d\n",y,x);
				return 0;
			}
			x ++;
		}
	}
	return 0;
}
