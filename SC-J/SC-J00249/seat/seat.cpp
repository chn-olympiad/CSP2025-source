#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int zw[11][11];
int n,m;
bool t(int x,int y){
	if(x>y)return true;
	else return false;
}
void go(int fx,int i,int x,int y){
	
	if(i==n*m)return;
	if(fx==1&&x+1>n){
		fx=0;
		//cout<<fx<<" ";
		zw[x][y]=a[i];
		go(fx,i+1,x,y+1);
	}else if(fx==0&&x-1<1){
		fx=1;
		zw[x][y]=a[i];
		go(fx,i+1,x,y+1);
	}else{
		if(fx){
			zw[x][y]=a[i];
			go(fx,i+1,x+1,y);
		}else{
			zw[x][y]=a[i];
			go(fx,i+1,x-1,y);
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	int cj;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cj=a[1];
	sort(a+1,a+n*m+1,t);
	go(1,1,1,1);
	//cout<<endl<<"-------"<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(cj==zw[i][j]){
				cout<<j<<" "<<i;
				return 0;
			}
		//	cout<<zw[i][j]<<" ";
		}
	//	cout<<endl;
	}
	return 0;
} 