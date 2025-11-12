#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,k;
int a[N];

void pts30(){
	//特殊性质A和B的点
	//性质B似乎包含了性质A 
	//性质A：k=0,a[i]=1; 分类讨论
//	if(k==0){
//		//偶数个，直接两两异或
//		//奇数个，去掉一个两两异或 
//		//其实就是向下取整 
//		cout<<n/2; 
//		return ;
//			
//	} 
	
	//性质B：a[i]=0或1 k=0或1 分讨
	int cnt=0,cnt2;
	if(k==0){
		//直接数0的个数，加上连着的1 
		for(int i=1;i<=n;i++){
			if(a[i]==0) cnt++;        //边界 
			if((a[i]==1 && a[i+1]==1)|| (a[i-1]==1 && a[i]==1 && a[i+1]==0)) cnt2++;
		} 
		cout<<cnt+(cnt2>>1);
	}else{
		//k=1时直接数1的个数
		for(int i=1;i<=n;i++){
			if(a[i]==1) cnt++;
		} 
		cout<<cnt;
	}
	 
}
int ma=-1;//判断特殊性质 
int flag=0;
int main(){
	//期望30pts 代码有warning 希望不会CE 
	 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=2 && a[i]!=a[i-1]) flag=1;
		ma=max(ma,a[i]);
	} 
	if( (k<=1) && ma<=1 ){ //符合特殊性质A和B
		pts30();
		return 0;		 
	}
	
	if(flag==0 && a[1]==k){
		cout<<n;//万一骗到了 
	}
	
	//想下特殊C，三个性质打完70pts有了 
	 
	return 0;
}
