#include<bits/stdc++.h>
using namespace std;
string s;
int box[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			box[s[i]-'0']++;
			//统计数字个数 
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=box[i];j++){
			cout<<i;
			//从9到0输出（保证一定有非零数作为首位） 
		}
	}
	return 0;
}
