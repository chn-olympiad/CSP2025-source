//求什么?
//给定一个字符串,其中包含多个数字
//要求将字符串中数字进行排列,得出一个最大的数

//怎么做? 
//定义一个数组num1_[10]
//其中num1_[x]=y表示数字x出现了y次
//先统计字符串中数字出现的次数 
//然后从高到低,将x输出num1_[x]次 

//特别的
//如果其中全都是0,那么只需要输出0 

#include<bits/stdc++.h>
using namespace std;

long long num1_[10];
//计数用的数组,其中num1_[x]=y表示x出现了y次 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	getline(cin,s);
	//输入通过 
	
	long long len=s.length();
	//长度获取通过
	 
	for(long long i=0;i<len;i++){
		if(char(s[i])>='0' && char(s[i])<='9'){
			//数字判断通过 
			short orn1_;
			orn1_=char(s[i])-'0';
			num1_[orn1_]++;
			//计数通过 
		}
		
	}
	
	bool alsero0_=true;
	//如果输出了i且i!=0,那么alsero0_=false
	//否则其不变,0前面没有数,只需输出一个0 
	for(int i=9;i>=0;i--){
		for(long long j=num1_[i];j>0;j--){
			cout<<i;
			//如果num1_[i]==0,则不会进入循环
			//如何num1_[i]>0,则有几次输出几次
			if(i>0){
				alsero0_=false;
			}
			else{//i==0
				if(alsero0_){//前面没有数 
					break; 
				}
			}
		}
	}
	 
	return 0;
	//解注释 
}
