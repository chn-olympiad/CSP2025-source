#include<bits/stdc++.h> 
using namespace std;
const int N=20,M=20;
int a[N*M];
int n,m,R,Rpos;
int col=0,line=0;
void work(){
	col=0,line=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==R) {
			Rpos=i;break;
		}
	}
	
	int groups=Rpos/(n*2);
	col+=groups*2;
	//in one group:
	int mod=Rpos%(n*2);
	//0<=mod<2n
	
	for(int i=1;i<=mod;i++){
		if(i==1){
			col++;
		}else if(i<n+1){//down:2~n+1
			line++;
		}else if(i==n+1){
			col++;
		}else{//n+1<=i<n*2
			col--;
		}
//		printf("i=%d,(%d,%d)\n",i,line,col);
	}
	printf("%d %d",col,line);
	return;
}
void pt(){
	for(int i=1;i<=n*m;i++){
		cout<<a[i]<<' ';
	}
	cout<<endl;
	return;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;//n––m¡– 
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	work();
	return 0;
} 
