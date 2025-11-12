#include<cstdio> 
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int N = 2000005;
int a[N];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	int o = 0;
	cin>>s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] < 'a'){
			a[++o] = s[i]-'0';
		}
	}
	sort(a+1, a+o+1);
	for(int i = o; i >= 1; i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 