#include<bits/stdc++.h>
using namespace std;
int a[105];//成绩 
int n,m;
int tool,loot;
int	c,r; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	tool=n*m;
	for(int i=1;i<=tool;i++){
		cin>>a[i];
	}
	loot=a[1];
	//将成绩从大到小排序
	for(int i=1;i<tool;i++){
		for(int j=1;j<=tool-i;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	//找到小R的位置
	for(int i=1;i<=tool;i++){
		if(a[i]==loot){
			loot=i;
			break;
		} 
	}
	//计算列和行
	if(loot%n==0){
		c=loot/n;
	}
	else{
		c=loot/n+1;
	}
	//如果是奇数列 
	if(c%2!=0){
		if(loot%n==0){
			r=n;
		}
		else{
			r=loot%n;
		}
	}
	else{
		if(loot%n==0){
			r=1;
		}
		else{
			r=n-loot%n+1;
		}
	}
	cout<<c<<' '<<r;
	return 0;
}
