#include<bits/stdc++.h>
using namespace std;
int n,m,r[1005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int cnt=n*m;
	
	for(int i=1;i<=cnt;i++){
			scanf("%d",&r[i]);
	}int a=r[1];
	sort(r+1,r+1+cnt,cmp);
	int x,y;
	
	for(int i=1;i<=cnt;i++){
		if(r[i]==a){
			x=i/n,y=i%n;
			if(y>0) x++;
			else y=n;
			if(x%2==0) y=n-y+1;
			break;
		}
	}
	printf("%d %d",x,y);
	
	return 0;
}

