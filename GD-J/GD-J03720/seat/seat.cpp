//我承诺遵守中国计算机学会相关规定
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
int seats[14][14];
int score[110];
bool cmp(const int&a, const int &b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0; i<(n*m); ++i){
		cin>>score[i];
	}
	int rc=score[0];//save R's score
	sort(score,score+(n*m),cmp);
	int list=1;
	for(int i=0; i<(n*m); ++i){//search R's score
		if(score[i]==rc) break;
		list++;
	}
	int x=1,y=1;
	while(list-1){//find R's seat, like a snake
		if(x%2==1){
			if(y==n){
				x++;
			}
			else{
				y++;
			}
		}
		else{
			if(y==1){
				x++;
			}
			else{
				y--;
			}
		}
		list--;
	}
	cout<<x<<" "<<y;
	//The R is <adj.调皮的>
	return 0;
}
/*???
10*10这可以枚举吧
先排序确定小R的排名
然后依次枚举座位
奇数从小到大偶数从大到小
这不就搞定了 
*/










//#define int long long
//int itn nit nti tin tni
//main mian mnai mnia mani mina
/*
8:55 建完个人信息txt然后接着做题 
8:56 ## 【题目描述】CSP-J 2025 第二轮正在进行。
     你怎么知道:)
9:15 过样例，等等先造数据
9:18 过自测，下一题 
*/ 
//目测<普及-> 
//100+100+0+0=200, 3= prize
