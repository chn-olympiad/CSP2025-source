#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N],b[N][N],sum,cnm,id,c;
bool cmp(int x,int y){
	return x>y; 
}
int main(){
	freopen("seat1.in","r",stdin);
	freopen("seat1.out","w",stdout);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	c=n*m;//n*m的值 
	for(int i=1;i<=c;i++){
		cin>>a[i];
	}cnm=a[1];//小R的成绩 
	sort(a+1,a+c+1,cmp);//排序 
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				b[j][i]=++sum;
			} 
		}else{
			for(int j=n;j>=1;j--){
				b[j][i]=++sum;
			}
		}
	}//处理座位 
	for(int i=1;i<=c;i++){
		if(a[i]==cnm){
			id=i;
		} 
	} //找出小R在第几位 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==id){
				cout<<j<<" "<<i;//找出小R的座位并输出 
				return 0;
			} 
		}
	} 
	return 0;
}
