#include<bits/stdc++.h>
using namespace std;
string s,a;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char c;
	while(cin >> c){
		if(isdigit(c)) a+=c;
	}
	sort(a.begin(),a.end(),cmp);
	cout << a;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
