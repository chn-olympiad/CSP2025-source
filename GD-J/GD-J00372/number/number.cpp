#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
//定义
string s;
int num[1000001];//存储1-9数字的数组 
//排序函数
int fun(int a,int b){
	return a>b;
} 
int main(){
	//文件操作
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout);
	//输入
	cin>>s;
	//遍历字符串s并找出位于1-9之间的数字
	int cnt=0;//整数数组的下标 
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt++;
			num[cnt]=s[i]-'0';
		}
	}
	//对整数数组进行排序
	sort(num+1,num+cnt+1,fun); 
	//输出
	for(int i=1;i<=cnt;i++){
		cout<<num[i];
	} 
	//文件操作
	fclose(stdin);
	fclose(stdout); 
	return 0;
}

