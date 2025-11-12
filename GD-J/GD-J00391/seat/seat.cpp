#include<bits/stdc++.h>
using namespace std;

int n,m;//有n列m行 
int a[105];//成绩 
int c,r;//c列r行
int R,rs;//小R的成绩,排名 

int main(){
	frepoen("seat.in","r","stdin");
	freopen("seat.out","w","stdout");
	cin>>n>>m;
	int s=m*n;
	for(int i=1;i<=s;++i){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+s+1);//从小到大 
	for(int i=1;i<=s;++i){
		if(a[i]==R){
			rs=s-i+1;//因为是从小到大，所以排名要从后面开始算 
		}
	}
	//列 
	if(rs%n==0){//刚好在第一个或最后一个 
		c=rs/n;
	}else{
		c=rs/n+1;//有余数，多加一列 
	}
	//行 
	if(c%2==0){//如果在偶数列，从后面开始 
		if(rs/n==1){//刚好在最后一个 
			r=n;
		}else{
			r=n-(rs/n);
		}
	}else{//奇数列，从前面开始 
		if(rs%n==0){
			r=n;
		}else{
			r=rs%n;
		}
	}
	
	cout<<c<<" "<<r;
	
	return 0;
}
