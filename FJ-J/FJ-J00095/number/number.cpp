#include<bits/stdc++.h>
using namespace std;
string s;
int a[13];
int main(){
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);	
	cin>>s;
	for(int i=0;i<s.size();i++){
		int m=s[i]-'0';
		if(m>=0&&m<=9){//如果是数字，存入桶
		    a[m]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++) printf("%d",i);//从大到小输出 
	}
	return 0;
}
//使用s中的任意多个数字，按任意顺序拼成一个正整数
//运用桶记录每个数个数，然后从大到小输出，以保证数最大，零也要存 
