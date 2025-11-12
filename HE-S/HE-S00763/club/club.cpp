//求什么?
//求一个非负整数,表示符合要求的分配方案满意度最大值

//怎么求?
//卧槽,这玩意是不考我贪心呢 

//先整个二维数组出来

//卧槽~  有特殊性质

//特殊性质A: 所有的a[i][2]==a[i][3]==0;
//这种情况只需要选取满意度前x高的进去就行
//特殊性质B: 所有的a[i][3]==0;
//这种情况就是二选一,这个先放着 

#include<bits/stdc++.h>
using namespace std;

bool bmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	
	for(;t>0;t--){
		int peumber1_;//人数
		cin>>peumber1_;
		int a[peumber1_+1][4];
		bool a2_zero=true,a3_zero=true;
		//a[x][y]表示第x个人对第y个部门的满意度
		
		for(int i=1;i<=peumber1_;i++){
			for(int j=1;j<4;j++){
				cin>>a[i][j];
				if(a[i][2]!=0&&j==2){
					a2_zero=false;
				}
				if(a[i][3]!=0&&j==3){
					a3_zero=false;
				}
			}		
		}
		//输入(通过)加判断(通过)
		
		if(a3_zero){//符合特殊性质A,B
			if(a2_zero){
			//符合特殊性质A
				int b[peumber1_+1];
				for(int i=1;i<=peumber1_;i++){
					b[i]=a[i][1];
					//转移进去(通过) 
				}
				//这时间复杂度得高成啥鸟样了
				
				sort(b+1,b+peumber1_+2,bmp);
				//排序(通过) 
				//b[0]=0,剩下的按照从大到小排序 
				
				int sum1_=0;//sum是计数器
				for(int i=1;i<=peumber1_/2;i++){
					sum1_+=b[i]; 
				}
				cout<<sum1_<<endl;
				continue;
			}
			
			//符合特殊性质B
			//草,不会
			cout<<rand();
			continue;
		}
		cout<<rand();
		continue;
	}
	
	return 0;
	//解注释 
}
