#include<bits/stdc++.h>
using namespace std;
string s;//字符串
int a[15];//hush数组 
bool pd=true;//特判 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){ //如果是数字 
			int b=s[i]-'0';
			a[b]++;//数字出现次数++ 
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]!=0&&i!=0){//如果有非零数字存在，就不进行特殊处理 
			pd=false;
		}
		if(i==0&&pd==true){//只有0特殊处理 
			cout<<0;
			return 0;
		}
		for(int j=1;j<=a[i];j++){//倒序输出 
			cout<<i;
		}
	}
	
	return 0;
} 
