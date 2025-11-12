#include <bits/stdc++.h>
using namespace std;
int n,m;
struct moi{
	int list,num;
}a[150];
bool cmp(moi p,moi o){
	return p.num > o.num;
}
int main(){
    freopen("seat.in","r","stdin");
	freppen("seat.out","s","stdout");
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n*m ; i++){
		scanf("%d",&a[i].num);
		a[i].list = i;
	}
	int k = m*n;
	sort(a+1,a+1+k,cmp);
	int x = 0,y = 1;
	for(int i = 1 ; i <= n*m; i++){
		if(y % 2)x++;
		else x--;
		if(x > n){
			y++;
			x--;
		}
		if(x == 0){
			y++;
			x++;
		}
		if(a[i].list == 1){
		    cout << x << ' ' << y; 
			return 0;	
		} 
	}
	return 0;
} 