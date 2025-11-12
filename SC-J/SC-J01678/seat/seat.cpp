#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[110];//n行数，m列数 
	cin>>n>>m;
	//基本数据 
	int sum=n*m;//记录总数量 
	for(int i=1;i<=sum;i++){//输入成绩 
		cin>>a[i];
	} 
	int r=a[1];//标记小r的成绩
	for(int i=1;i<=sum;i++){
		for(int j=1;j<=sum;j++){//选择排序，从大到小 
			if(a[i]>a[j]){
				int p=a[i];//p临时变量
				a[i]=a[j];
				a[j]=p; 
			}
		}
	} 
	//寻找位置
	for(int i=1;i<=sum;i++){
		if(a[i]==r){
			r=i;//标记小r的排名 
		}
	} 
	//定位坐标 
	int x,y;
	//确定x，组数 
	if(r<=n){
		x=1;
	}else if(r%n==0){
		x=r/n;
	}else {
		x=r/n+1;
	}
	//确定y，排序，分奇偶 
	int q=r/n;//初步名次 
	if(x%2==0){//偶数 
		if(q==0){
			y=1;
		} else{
			y=n-q+1;
		}
	} else{//奇数 
		if(q==0){
			y=n;
		} else{
			y=q;
		}
	} 
	cout<<x<<" "<<y<<endl; 
	return 0;
}




