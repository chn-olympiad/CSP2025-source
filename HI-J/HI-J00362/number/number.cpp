#include<bits/stdc++.h>
using namespace std;
string s;
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	getline(cin,s);
	for(int i = 0;i<=s.size()-1;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	bool flag = 0;
	for(int i = 9;i>=0;i--){
		for(int j = 1;j<=a[i];j++){
			cout<<i;
			if(i==0&&flag == 0){
				return 0;
			}else{
				flag = 1;
			}
		}
	}
	return 0;	
}
