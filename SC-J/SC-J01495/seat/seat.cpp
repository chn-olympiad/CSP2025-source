#include<bits/stdc++.h>
using namespace std;

int n=0,m=0;
int j=1,z=1;
bool flag=0;
int tmp=0,sum=1;

struct zb{
	int x;
	int y;
	int chengj;
}a[110];//结构体储存x，y 

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin>>n>>m;
	int t=n*m;//处理个数 
	
	for(int i=1;i<=t;i++){
		cin>>a[i].chengj;
	}//输入 
	
	int xR=a[1].chengj;//储存小R的成绩 
	
	for(int i=1;i<=t;i++){
		for(int s=1;s<=t;s++){
			if(a[s].chengj < a[s+1].chengj){
				swap(a[s],a[s+1]);
			}
		}
	}//冒泡排序 

		for(int i=1;i<=m;i++){
			
			if(i%2==0) flag=1;//判断奇偶 
			else flag=0;
			
			if(flag==0){//偶行 
				for(j=1;j<=n;j++){
					a[sum].y=i;
					a[sum].x=j;
					tmp=j;//n个为一组，正序 
					sum++;
				}
			}
			else if(flag==1){//奇数行 
				for(z=tmp;z>=1;z--){//蛇形：从下到上 
					a[sum].y=i;
					a[sum].x=z;//n个为一组，正序 
					sum++;//处理下一个成绩 
				}
			}
		}
	
		
	
	for(int q=1;q<=t;q++){
		if(a[q].chengj==xR){
			cout<<a[q].y<<" "<<a[q].x;//输出ij 
		}
	}
	return 0;
}