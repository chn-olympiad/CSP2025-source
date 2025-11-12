#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[5000001];
long long b[5001][5001];
long long o;
long long aa;
bool cmp(int a1,int b1){
	return a1>b1;
}
void ee(int t,int x,int y){
	//cout<<x<<' '<<y<<endl;
	if(t==o){
		cout<<x<<' '<<y;
	return;
	}
	int oo=x%2;
	if(oo==1){
		if(y<n){
		int yty=y+1;
	if(b[x][yty]==0){
		b[x][yty]=1;
		ee(t+1,x,yty);	
		}}
       if(y==n){
       	int xtx=x+1;
       	if(b[xtx][y]==0&&xtx<=m){
       		b[xtx][y]=1;
       		ee(t+1,xtx,y);
		   }
	   }
	
	}
else	if(oo==0){
		if(y>1){
		 int yty=y-1; 
		 if(b[x][yty]==0){
		b[x][yty]=1;
		ee(t+1,x,yty);		
		}
	}
	else if(y==1){
		 	int xtx=x+1;
       	if(b[xtx][y]==0&&xtx<=m){
       		b[xtx][y]=1;
       		ee(t+1,xtx,y);
		   }
	}
}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		aa=a[1];
	}
	sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
    	if(a[i]==aa){
    		o=i;
    		break;
		}
	}
	ee(1,1,1);
	return 0;
}
