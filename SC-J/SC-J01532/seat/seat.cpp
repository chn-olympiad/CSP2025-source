#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m;
int k=1,f=1;
int x,rscore;
priority_queue<int>seat;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&rscore);
	seat.push(rscore);
	for(int i=2;i<=n*m;i++){
		scanf("%d",&x);
		seat.push(x);
	}
	while(seat.top()!=rscore){
		if(k==n&&f%2==1||k==1&&f%2==0) f++;
		else if(f%2==1&&k!=n) 		   k++;
		else if(f%2==0&&k!=1) 		   k--;
		seat.pop();
	}
	
	printf("%d %d",f,k);
	return 0;
}

