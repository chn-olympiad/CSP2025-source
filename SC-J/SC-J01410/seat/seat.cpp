#include<bits/stdc++.h>
using namespace std;
int n,m,a,tot,x,y,cnt=1;
priority_queue<int> q;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	tot=n*m;
	scanf("%d",&a);
	q.push(a);
	for(int i=2,j;i<=tot;i++){
		scanf("%d",&j);
		q.push(j);
	}
	while(q.top()!=a){
		cnt++;
		q.pop();
	}
	x=(int)ceil((double)(cnt)/n);
	if(x&1){
		y=cnt%n;
		if(y==0) y=n;
	}else{
		y=cnt%n;
		if(y==0) y=n;
		y=n-y+1;
	}
	printf("%d %d",x,y);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
