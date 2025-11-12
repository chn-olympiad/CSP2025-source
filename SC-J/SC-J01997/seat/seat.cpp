#include<iostream>
#include<cstdio>
#include<string> 
using namespace std;
int n,m;
int k=1,q=1,direct=1,c=1;//k是行，q是列 
int y[101][101];
int z[1000001];
void paixu(){
	for(int i=1;i<=n*m;i++){
		for(int j=i;j<=n*m;j++){
			int a,b;
			if(z[i]>z[j]){
				a=z[i],b=z[j];
				z[i]=b,z[j]=a;
			}
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>z[i];
	}
	int a1=z[1];
	paixu();//从小到大排序 
	int p=n*m,xuhao=1;//p是从最高分到最低分，xuhao是座位轨迹的序号 
	y[1][1]=z[p];//第一个座位是最高分 
	while(c<=n*m){//循环n次 
		if(direct==1&&k+1<=n){//如果向下走 
			k++,p--,xuhao++;//行数加以1 
			y[k][q]=z[p];
		
		}else if(xuhao%n==0&&(xuhao/n)%2==1){//如果在第n行,且需要向右走时 
			q++,xuhao++,p--;//列数加1 
			y[k][q]=z[p];
			
		}else if(xuhao%n==1&&(xuhao/n)%2==1){//如果在第n行,且需要向上走时
			direct=2;//向上走的标志
			
			xuhao++,k--,p--;//行数减少 
			y[k][q]=z[p];
		}else if(xuhao%n==0&&(xuhao/n)%2==0){//如果在第1行,且需要向右边走时
			direct=2;
			q++,p--,xuhao++;//列数加1 
			y[k][q]=z[p];
		}else if(xuhao%n==1&&(xuhao/n)%2==0){//如果在第1行，且需要向下走的时候 
			direct=1;//向下走 
			xuhao++,k++,p--;//行数加一 
			y[k][q]=z[p];
		}else if(direct==2&&k-1>=1){
			k--,xuhao++,p--;//行数减掉1 
			y[k][q]=z[p];
		}
		c++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(y[i][j]==a1){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
} 