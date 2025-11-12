#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
char ch;
string str;
long long num[10],tmp;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	long long l=str.size();
	for(long long i=0;i<l;i++){
		ch=str[i];
		if(ch>='0'&&ch<='9'){
			tmp=ch-'0';
			num[tmp]++;	
		}
	}
	for(long long i=9;i>=0;i--){
		for(long long j=0;j<num[i];j++){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
