#include<bits/stdc++.h> 
using namespace std;
long n,m;//长，宽 
long f=1;//位置
long r;//小R的成绩
long ansh,ansl;//行和列 
long cj[1000];//成绩，其实100就够了
long zw[100][100];//座位 
bool cmp(int d,int e){
	return d>e;
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
 scanf("%d%d",&n,&m);//cin>>n>>m;
for(int i=1;i<=n*m;i++){
	scanf("%d",&cj[i]);//cin>>cj[i];
}
r=cj[1]; 
//-------------------------------------- 
//for(int i=1;i<=n*m;i++){
//	printf("%d",cj[i]);//cin>>cj[i];
//}试一下scanf,printf写对没
sort(cj+1,cj+1+n*m,cmp);//排序一下
//for(int i=1;i<=n*m;i++) cout<<cj[i];
for(int i=1;i<=m;i++){//打表 
	if(i%2==1){//奇数 
	for(int j=1;j<=n;j++){//从上到下 
		zw[j][i]=cj[f];
		f++;
	}
}else{
	for(int j=n;j>=1;j--){//从下到上 
		zw[j][i]=cj[f];
		f++;
	}
}
} 
//for(int i=1;i<=n;i++){
//	for(int j=1;j<=m;j++){
//		cout<<zw[i][j]<<" "; 
//		}
//		cout<<endl;
//	}
	



for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++){
		if(zw[i][j]==r){//找成绩 
			printf("%d",j);
			cout<<" ";//printf的” “怎么写？？？？？？？？？ 
			printf("%d",i);
			break;
		}
	}
}

//3 3
//1 2 3 4 5 6 7 8 9
//
//9 4 3 
//8 5 2 
//7 6 1 
//
//3 2
//6 5 4 3 2 1 
//
//6 1 
//5 2 
//4 3 
//
//10 1
//1 2 3 4 5 6 7 8 9 10
//
//10
//9
//8
//7
//6
//5
//4
//3
//2
//1 
//可以用sort后的位置/n的商向上取整得到（=）第几列 
//如果为偶数列，从下往上数，从n*列数减一开始 
//如果为奇数列，从上往下数，从n*列数减一开始
//其实还可以再化简，但数据太小，没必要 
	return 0;
}

