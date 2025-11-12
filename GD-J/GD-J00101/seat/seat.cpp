#include<bits/stdc++.h>
using namespace std;
int n,m,sc[110],a,pos,x,y; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",sc+i);
	}
	a=sc[1];
	sort(sc+1,sc+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(sc[i]==a){
			pos=i;
			break;
		}
	}
	pos=n*m-pos+1;
	if(pos%n==0)x=pos/n;
	else x=pos/n+1;
	if(x%2==0){
		y=(n+1-(pos%n))%n;
		if(y==0)y=n;
	}
	else{
		y=pos%n;
		if(y==0)y=n;
	}
	printf("%d %d",x,y);
	return 0;
}

