#include<bits/stdc++.h>
using namespace std;
int a[101];	//成绩 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;	//列m，行n 
	cin>>n>>m;
	int num=n*m;
	cin>>a[1];
	int R=a[1];	//小R成绩 
	for(int i=2;i<=num;i++)
		cin>>a[i];
	sort(a+1,a+num+1,greater<int>()); 
	int c,r;	//小R坐第c列第r行 
	for(int i=1;i<=num;i++)	//枚举下标 
		if(a[i]==R){
			int d=(i-1)/n;
	//		cout<<"d---->"<<d<<"\n"; //测试语句 
			c=d+1;
			if(d%2==0)
				r=i-d*n;
			else
				r=n-(i-d*n)+1;
		}
	cout<<c<<" "<<r;
	return 0;
} 