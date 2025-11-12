#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int a[200];
int main(){
									//文件读写
									//数据范围 
									//输出格式 
									//别挂分pls 
									//一等pls 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int i;
	for(i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int R=a[1];
	int Paim=1;
	for(i=2;i<=n*m;i++){
		if(a[i]>R)Paim++;
	}
	int x=(Paim-1)/n+1;
	int y;
	int qqq;
	qqq=Paim%n;
	if(qqq==0)qqq=n;
	if(x%2==0){
		y=n-(qqq-1);
	}
	else{
		y=(qqq);
	}
	cout<<x<<' '<<y;
	return 0;
} 


