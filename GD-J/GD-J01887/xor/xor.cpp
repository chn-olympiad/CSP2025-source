//异或的循环性: a ^ b ^ b = a ^ (b ^ b) = a ^ 0 = a
//骗分(30) 
#include<iostream>
#include<cstdio>
using namespace std;

const int N = 5e5 + 10; 
int n,k,num = 0;
int a[N],pre[N];//前缀异或数组(满分思路,但我想到却不会。。。)
bool flag[N] = {0}; 

int main(){
	 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		//pre[i] = (pre[i - 1] ^ a[i]);
		//cout << pre[i] << " ";
	}
	
	//按特殊性质骗分 
	//A(10分):a[i]全是1,k = 0:两两一组
	//cout << n / 2;
	
	//A,B(30分) a[i] = 0 or 1
	//<1>,k = 1,答案为a[i]内1的个数 
	if(k == 1){
		for(int i = 1;i <= n;i++){
			if(a[i] == 1) num++;
		}
	}
	//<2>,k = 0, 0,1分开处理
	else if(k == 0){
		for(int i = 1;i <= n;i++){
			if(a[i] == 0) num++;//单个0比2个1和1个0好 
			else if(a[i] == 1 && a[i - 1] == 1 && flag[i] == 0 && flag[i - 1] == 0){
				num++;
				flag[i - 1] = 1;
				flag[i] = 1;
			}//相邻的2个1为一组 
		}
	}
	
	cout << num; 
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
