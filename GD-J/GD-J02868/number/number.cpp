#include<iostream>
#include<algorithm>
#include<string>
#include<cctype>
using namespace std;

int a[1000100];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int n = 0;
	cin>>s;
	for(char c : s){
		if(isdigit(c)){
			a[++n] = c-'0';
		}
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i = 1; i <= n; i++){
		cout<<a[i];
	}
	return 0;
} 
