//求什么?
//R的座位(从左向右c个,从上至下r个)

//怎么分座位?
//给定两个数n,m,考场是一个n行m列的方阵
//然后给出n*m个数,代表每一位考生的成绩
//其中第一个数是R的成绩,成绩按照从高到低蛇形排列

//怎么求?
//局外定义rex2_,rey2_,m,n作为函数返回值
//先定义一个函数nexeat2_(x,y)表示他的下一个座位 
//其中x代表列数(左至右),y代表行数(上至下) 
//如果x是奇数:
//	y++(y!=n)
//  x++(y==n)
//否则x是偶数:
//	y--(y!=1)
//	x++(y==1)
//然后sort排序分数的数组,按照顺序循环判断
//如果不是就nexeat,是的话就输出上一次的结果 

#include<bits/stdc++.h>
using namespace std;

int rex2_=1,rey2_=1,m,n;
void nexeat2_(int x,int y){
	rex2_=x;rey2_=y;
	if(x%2==1){
		if(y!=n){
			rey2_++;
		}
		else{
			rex2_++;
		}
	}
	else{
		if(y!=1){
			rey2_--;
		}
		else{
			rex2_++;
		}
	}
	return;
}
//函数通过
bool bmp(int x,int y){
	return x>y;
} 
 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin>>n>>m;
	
	int point2_[n*m+1],R;
	//数组表示总共分数,R表示R的分数
	cin>>R;
	point2_[1]=R;
	for(int i=2;i<=n*m;i++){
		cin>>point2_[i];
	}
	//输入
	
	sort(point2_+1,point2_+n*m+1,bmp);
	//排序通过 
	
	for(int i=1;i<=n*m;i++){
		if(point2_[i]==R){
			cout<<rex2_<<' '<<rey2_;
		}
		else{
			nexeat2_(rex2_,rey2_);
		}
	}
	
	return 0;
	//解注释 
}
