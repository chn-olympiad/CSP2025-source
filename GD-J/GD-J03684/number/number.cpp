#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int cnt[N];//计数
int dep=0; 

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='a'&&s[i]<='z'){
			continue;
		}
		cnt[s[i]-'0']++;//记录出现次数 
	}
	for(int i=9;i>=0;i--){
		while(cnt[i]--){
			cout<<i;//从大到小输出即可 
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
//00000098989 //一组数据 
