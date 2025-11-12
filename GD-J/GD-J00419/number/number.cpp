#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	int sum=0,len=sizeof(s)/sizeof('0'),ment=0;
	long long shu[15] = {0};
	for(int i=0;i<len;i++){
		if(s[i] <='9' and s[i] >= '0'){
			shu[s[i]-48]++;
		}
	} 
	for(int i=9;i>=0;i--){
		for(int j=0;j<shu[i];j++){
			cout << i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
