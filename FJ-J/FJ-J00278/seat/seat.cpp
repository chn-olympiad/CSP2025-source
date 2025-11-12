#include<bits/stdc++.h>
using namespace std;
int a[105];
bool o(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int s=n*m;
	for(int i=0;i<s;i++){
		scanf("%d",&a[i]);
	}
	int p=a[0];
	sort(a,a+s,o);
	int x=0,y=0;
	bool gd=1;
	for(int i=0;i<s;i++){
		if(a[i]==p){
			break;
		}
		if(gd){
			if(++x==n){
				y++;
				x--;
				gd=0;
			}
		}
		else{
			if(--x<0){
				y++;
				x++;
				gd=1;
			}
		}
	}
	printf("%d %d",y+1,x+1);
}
