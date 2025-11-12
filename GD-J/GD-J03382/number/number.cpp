#include<bits/stdc++.h> 
using namespace std;
string s;
int num[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char i:s){
		if(i>='0'&&i<='9') num[i-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(num[i]){
			cout<<i;
			num[i]--;
		}
	}
	return 0;
}
