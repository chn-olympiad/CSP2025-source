#include<bits/stdc++.h>
using namespace std;
int n,m,sc;int num;
int tong[101];//最高分为100 最低为1
int adress;
//n和m很小 最大只有10 
int main(){
	
	//一定记得取消注释 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	//蛇形 (1,1)->(2,1)->(2,2)->(1,2) n=2,m=2
	//s1>s2>s3>s4  分高的排前面
	
	
	//n为行 m为列 sc为R分数
	cin>>n>>m;cin>>sc;adress=max(adress,sc);
	num=n*m-1;//num为除了R还有几人 方便输入
	tong[sc]+=1;
	
	//求R在几行几列
	int tmp;//方便输入 
	for(int i=1;i<=num;i++){
		cin>>tmp;tong[tmp]+=1;adress=max(adress,tmp);
	}
	//数据保证分数各不相同
	
	
	
	//全局变量adress拿来存当前学生分数 (tong的下标) 
	int y;y=1;
	while(y<=m){
		
		if(y%2!=0){
			for(int x=1;x<=n;x++){
				while(tong[adress]==0)adress--;
				if(adress==sc){
					cout<<y<<' '<<x;//先输出列 再是行!!
					
					fclose(stdin);
					fclose(stdout);
					return 0; 
				}
				tong[adress]--;
			}
		}
		
		else if(y%2==0){
			for(int x=n;x>=1;x--){
				while(tong[adress]==0)adress--;
				if(adress==sc){
					cout<<y<<' '<<x;//先输出列 再是行!!
					
					fclose(stdin);
					fclose(stdout);
					return 0; 
				}
				tong[adress]--;
			}
		}
		
		y+=1;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
