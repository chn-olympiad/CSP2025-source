#include<bits/stdc++.h>
using namespace std;
struct GTI{
	bool isXiaoming;
	int number;
}a[200];
bool cmp(GTI x,GTI y){
	return x.number>y.number;
}
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		int ls;
		scanf("%d",&ls);
		a[i].number=ls;
		a[i].isXiaoming=false;
	}
	a[1].isXiaoming=true;
	sort(a+1,a+1+n*m,cmp);
	int x=1,y=1;
	bool HFK=true;
	for(int i=1;i<=n*m;i++){
		if(a[i].isXiaoming){
			printf("%d %d\n",y,x);
			return 0;
		}
		if(HFK){
			if(x==n){
				y++;
				HFK=false;
			}
			else x++;
		}
		else{
			if(x==1){
				y++;
				HFK=true;
			}
			else x--;
		}
	}
	return 0;
}