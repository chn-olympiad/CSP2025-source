#include<bits/stdc++.h>
using namespace std;
int num[19];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		int num1=s[i]-'0';
		if(num1>=0&&num1<=9){
			num[num1]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(num[i]>0){
			cout<<i;
			num[i]--; 
		}
	}
	return 0;
}
