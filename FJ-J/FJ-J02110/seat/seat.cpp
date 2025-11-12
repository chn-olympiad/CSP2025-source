#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int n,m,hs,ls;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//输入 
	cin>>n>>m;//第n行，第m列 
	int sum=n*m;
	int sz[105];
	for(int i=1;i<=sum;i++){
		cin>>sz[i];
	}	
	// 
	int Grade=1; 
	//查询排名 
	for(int i=2;i<=sum;i++){
		if(sz[i]>sz[1]){
			Grade++;
//			cout<<sz[1]<<"->"<<sz[i]<<endl;
		}
	}
//	cout<<grade<<endl;
//	计算列数和行数 
	if((Grade%n)==0){
		//推测公式为：排名 / 行数 = 列数（向上取整） 
		ls=Grade/n;
		if((ls%2)==0){
			//推测情况：若此时为偶数列，则可证明此时顺序为倒序 
			hs=1;
		}else{
			//推测情况：若此时为奇数列，则可证明此时顺序为正序 
			hs=n;
		}
	}else{
		//推测公式为：排名 / 行数 = 列数（向上取整） 
		ls=Grade/n+1; 
		if((ls%2)==0){
			//推测情况：若此时为偶数列，则可证明此时顺序为倒序 
			hs=Grade%n;
			hs=n-hs+1;
		}else{
			//推测情况：若此时为奇数列，则可证明此时顺序为正序 
			hs=Grade%n;
		}
	}
	cout<<ls<<" "<<hs;
	return 0;
}
