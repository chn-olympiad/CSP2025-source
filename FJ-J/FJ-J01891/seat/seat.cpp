#include<iostream>
using namespace std;
int m,n,s[105],r,x[105],y[105],memory;
int main(){
	cin>>m>>n;
	for(int i=0;i<m*n;i++){
		cin>>s[i];
	}
	r=s[0];
// 成绩排序 
	for(int i=0;i<m*n;i++){
		for(int j=0;j<m*n;j++){
			if(s[j+1]>s[j]) swap(s[j],s[j+1]);
		}
	}
	// 储存小r成绩的下标 
	for(int i=0;i<m*n;i++){
		if(s[i]==r){
			memory=i;
			break;
		}
	}
	// 计算全考场座位坐标 
	for(int i=1;i<=n;i++) y[i]=i;
	for(int i=1;i<=m;i++) x[i]=i;
	// 输出 
	cout<<x[memory+1]<<' '<<y[memory+1];
	return 0;
}
