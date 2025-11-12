#include <bits/stdc++.h>
using namespace std;

int n,m,target;
int tempx,tempy,tempall;
int length;
int a[10005];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	//输入
	cin>>n>>m; 
	length=n*m;
	for(int i=1;i<=length;i++){
		cin>>a[i];
	}
	target=a[1];
	
	//排序
	sort(a+1,a+length+1,greater<int>());
	
	tempall=1;
	tempx=1;tempy=1; //坐标初始化
	
	while(tempall<=length && tempy<=m){

		if(a[tempall]==target) break;    //找到了
		
		if(tempy%2!=0){    //判断是向上还是向下，如果是奇数行向下，偶数行向上
			if(tempx+1<=n) {
				tempx++;    //向下一个
			}
			else{
				tempy++;   //如果到达最下面就来到下一行
			}
		}
		else{
			if(tempx-1>=1){
				tempx--;   //向上一个
			}
			else{
				tempy++;  //如果到达最上面就来到下一行
			}
		}
		tempall++;
	}
	
	cout<<tempy<<" "<<tempx;
	return 0;
}
