#include <bits/stdc++.h>
using namespace std; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,_,c,r;
	cin>>n>>m;//输入n,m
	int a[n*m+6];
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}//输入成绩 
	int R=a[1];//小R的成绩 
	sort(a+1,a+n*m+1);//排序 
	for (int i=1;i<=n*m;i++){
		if (a[i]==R){
			_=n*m-i+1;
			break;
		}
	}//小R的排名
	
	c=(_-1)/n+1;//列
	if (c%2){
		r=_%n;
		if (r==0) r=n;
	}
	else {
		r= n- _%n +1;
	}//行
	cout << c << " " << r;//输出 
	return 0;
}