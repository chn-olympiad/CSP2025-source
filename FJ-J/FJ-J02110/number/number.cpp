#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string str;//题目要求 
int ovo[15]={0};//桶排序的思想去做 
int main(){
	//日常freopen(1/1)
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//每日输入(1/1) 
	cin>>str;
	//正篇 
	for(int i=0;i<str.size();i++){//依次判断每一个字符 
		if(!(str[i]>='0'&&str[i]<='9'))continue;//如果不是数字就跳过 
		if((str[i]-'0')==9){
			//为了防超时这边如果碰到 9 都直接输出 
			cout<<9;
			//忘记要跳过了
			continue; 
		}
		ovo[str[i]-'0']++;//计算数量 
	}
	for(int i=8;i>=0;i--){//因为 9 已经直接输出了，因此从8开始输出 
		for(int j=1;j<=ovo[i];j++){
			cout<<i;
		}
	}
	return 0;
	//不一定完美但结束了的代码 
}
