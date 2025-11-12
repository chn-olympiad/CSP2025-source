#include<bits/stdc++.h>
using namespace std;
int c[10000000];
int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	int a,b;//座位 
	cin>>a>>b;
	int d[a][b]; 
	int x=1,y=1;//座位号 
	int updown=0;//向上为1，向下为0 
	int k=1;//轮到第几个人 
	
	for(int i=0;i<c.size();i++){//分数 
		cin>>c[i]; 
	}
	
	
	int n=strlen(c);
	int m=c[0];//小R的分数 
	sort(c,c+n+1);//排序 
	
	
	for(int i=0;i<=a;i++){
		for(int j=0;j<=b;j++){
			
			
			//判断是不是小R的座位 
			if(c[k]==m){
				cout<<d[x][y];
				return 0;
			}
			
			k++;
		}
		if(updown=0){
			x++;
			if(x==a) updown=1;
			x=1;
		}else{
			x--;
			if(x==1) updown=1;
			x=b;
		}
		
	}
	
	return 0;
}
	 

