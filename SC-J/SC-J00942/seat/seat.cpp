#include<bits/stdc++.h>
using namespace std;
const int N=13;
int a[N][N];
int n,m;
int mar=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1][1];
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i==1&&j==1) continue;
			cin>>a[i][j];
			if(a[i][j]>a[1][1]) mar++;
		}
	}
	if(mar==n*m-1) {
		cout<<m<<" "<<n;
		return 0;
	}
	if(mar==0){
		cout<<1<<" "<<1;
		return 0;
	}
	//n是行数 m是列数 
//	cout<<mar<<"\n"; 
	mar++;//确定自身排名 
	int ansa=mar/n,ansb=mar%n,ansc=1;//ansa确定列数，ansb检查是否能在ansa列装下，ansc确定行数 
	if(ansa==0) ansa=1;//第一列特判 
	if(ansb!=0) ansa++;//如果ansa列装不下，则加一列 
//待确定 
//	ansb++;//队列从1开始 故+1 
//	if(ansb>n) ansb=n;//防止超行
//	cout<<ansa<<" "<<ansb<<"\n";
	
	if(ansa%2==0){//疑似正确 偶数队列 从n到1 
	    ansc=n-ansb+1;
	}
	if(ansa%2!=0){//奇数队列 从1到n 
		ansc=ansb;
		if(ansb==0) ansc=n;
	}
	cout<<ansa<<" "<<ansc;
	return 0;
} 