#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];
int c=0,r,num,x,y;
int main(){
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		scanf("%d",&a[++c]);//c记录考生数 
		}
	}
	r=a[1];//存小R的成绩 
	sort(a+1,a+c+1);//给所有考生成绩排序 
	for(int i=1;i<=c;i++){
		if(a[i]==r){
			num=c+1-i;//找小R位置 
			break;
		} 
	}
	y=(num+n-1)/n;//计算列数
	if(y%2==1){//单数列 
		x=num-y*n+n;
	}else{
		x=y*n-num+1;
	} 
	printf("%d %d",y,x);
	return 0;
}
//sort快排，找出小R排名
//找到小R的列数,若是单数列，则从第一个到最后一个
//否则从最后一个到第一个 
