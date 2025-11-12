#include<bits/stdc++.h>
using namespace std;
int a[15];
int main(){
	//期望全对得100 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<=9;i++){
		a[i] = 0;//初始化
	}
	string s;
	cin >> s;
	int l = s.size();
	for(int i=0;i<l;i++){//遍历一遍 
		if(s[i]>='0'&&s[i]<='9'){//是数字 
			int num = s[i]-'0';////转成int值 
			a[num]++;//记录数字出现次数
		}
	}
	for(int i=9;i>=0;i--){//大的数字越靠前越好 
		for(int j=1;j<=a[i];j++){//有几个就输出几次 
			cout << i;//没有空格 
		}
	}
	return 0;
}