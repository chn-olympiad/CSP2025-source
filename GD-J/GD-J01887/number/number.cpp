#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

string s;
int ans[20];

int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	for(int i = 0;i < s.size();i++){
		int num = s[i] - '0';
		if(num >= 0 && num <= 9){
			ans[num]++;//Í°ÅÅÐòË¼Ïë 
		}
	}
	
	for(int i = 9;i >= 0;i--){
		for(int j = 1;j <= ans[i];j++){
			cout << i;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
