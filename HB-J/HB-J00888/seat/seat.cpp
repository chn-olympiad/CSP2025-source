#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[1001];
int u,p,c;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	u=n*m;
	for(int i=1;i<=u;i++)
		scanf("%d",&a[i]);
	p=a[1];
	sort(a+1,a+u+1,cmp);
	for(int i=1;i<=u;i++)
		if(a[i]==p)
			c=i;
	int x=1,y=1;
	int num=1;
	while(num+2*n<=c){
			num+=2*n;
			y+=2;
	}
	int flag=1;
	while(num<c){
		x+=flag;
		num++;
		if(x>n){
			x--;
			y++;
			flag=-1;
		}
	}
	printf("%d %d",y,x);
	return 0;
}
