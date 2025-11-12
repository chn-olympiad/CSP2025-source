//求什么?
//小R选出的小木棍能够拼成多少个多边形
//结果需%998 %244 %353

//怎么求?
//直接暴力得了,要么就排列组合,别的不会 

//666,题目要求取模,结果输出样例里边有个十万多的 

//算了就这样吧,太难了 
#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	cin>>n;
	
	int long4_[n];
	for(int i=0;i<n;i++){
		cin>>long4_[i];
	}
	
	int alplans4_=0;//总共可用方案 
	for(int i=3;i<=n;i++){//几条边
	//从3条边开始能拼成一个多边形 
		for(int j=0;j<=n-i+1;j++){//下标  
			int maxn=-1,sum=0;
			for(int k=0;k<i;k++){//个数 
				maxn=max(maxn,long4_[j+k]);
				sum+=long4_[j+k];
				//最大值与和 
			}
			if(sum>maxn*2){
				alplans4_++;
			}
		}
	}
	
	cout<<alplans4_%998%244%353;
	return 0;
	//解注释 
}
