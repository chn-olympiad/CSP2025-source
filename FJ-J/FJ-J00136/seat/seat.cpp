#include<bits/stdc++.h>
using namespace std;
int n,m,x=1,y=0,d=0;//n行m列  d方向,gx走后的x   坐标索引从1开始 
int dx[4]={0,1,0,1},dy[4]={1,0,-1,0};//0,2到边界转向 ，1 3 判到就转 
struct student{
	int score,id;
};
bool cmp(student x,student y){
	return x.score>y.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;//n行m列
	vector<student> a(n*m);
	for(int i=0;i<n*m;i++) {
		cin>>a[i].score;
		a[i].id=i+1;
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<n*m;i++) {
		//cout<<"人与分数:"<<a[i].id<<" "<<a[i].score<<"方向与坐标：";
		if(d%2==1)d=(d+1)%4;//如果d为1或3，立刻转向 
		if ( (i!=0 && y+dy[d]<=0) || y+dy[d]>n) d++;//排除第一位由1-0=>1-1的 情况下， 遇到边界转向 
		x+=dx[d];y+=dy[d];
		//cout<<d<<"　"<<x<<" "<<y<<endl;
		if (a[i].id==1){
			cout<<x<<" "<<y;
			return 0;
		}
	}
}
