#include<bits/stdc++.h>
using namespace std;
//运用桶从大往小依次是最高位 
//string去存遍历一遍维护数字
string ss;
int len;
int num[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>ss;
	len=ss.length();
	ss=' '+ss;
	for(int i=1;i<=len;i++){
		if(ss[i]>='0'&&ss[i]<='9'){
			num[ss[i]-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(num[i]--){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
