#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
//定义 
int n,k;
int data[5001];
int sum;
int main(){
	//文件操作
	freopen("xor.in","r",stdin); 
	freopen("xor.out","w",stdout);
	//输入
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>data[i];
	} 
	//循环求区间
	int he;//当前异或值
	bool yes=true;//是否是新区间 
	for(int i=1;i<=n;i++){
		if(yes==true){
			he=data[i];
			yes=false;
		}else{
			he=he^data[i];
		}
		if(he==k){
			sum++;
			yes=true;
		}
	} 
	//输出
	cout<<sum;
	//文件操作
	fclose(stdin);
	fclose(stdout);  
	return 0;
}

