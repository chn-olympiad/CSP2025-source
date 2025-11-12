#include<bits/stdc++.h>
using namespace std;
//通过数学方法进行找规律
//排序后，将新位置通过遍历找到
//然后对n取模做除法求出行列
//做除法后+1是列数 奇数列直接加取模，偶数列n-取模的数
int n,m,num,goal[1001],R;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	num=n*m;
	for(int i=1;i<=num;i++){
		cin>>goal[i];
	}
	R=goal[1];
	sort(goal+1,goal+num+1,cmp);
/*	for(int i=1;i<=num;i++){
		cout<<goal[i]<<' ';
	}
	cout<<R;*/
	for(int i=1;i<=num;i++){
		if(goal[i]==R){
			R=i-1;   //R本是存R的成绩，现在映射座位序号 
			break;
		}
	}
	int x,y;
	y=R/n+1;
	//错位处理   不错位需要单独处理取模为0的情况 
	x=R%n;
	if(y%2){
		cout<<y<<" "<<1+x;
	}else{
		cout<<y<<" "<<n-x;
	}
	return 0;
}

