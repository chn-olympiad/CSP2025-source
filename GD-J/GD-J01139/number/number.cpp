#include<iostream>
#include<cstdio>
using namespace std;
int Nm[10];
string s;
int main(){
									//文件读写
									//数据范围 
									//输出格式 
									//别挂分pls 
									//一等pls 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			Nm[s[i]-'0']++;
		}
	}
	int Guo=0;
	for(int i=9;i>=0;i--){
		if(i==0 && Guo==0){
			cout<<0;
			return 0;
		}
		for(int j=1;j<=Nm[i];j++){
			Guo=1;
			cout<<i;
		}
	}
	return 0;
} 
