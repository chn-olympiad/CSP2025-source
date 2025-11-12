#include<bits/stdc++.h>
using namespace std;
bool cmp(char a, char b) {
	return a>b;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;char ans[1000007]={-1};
	cin >> s;
	int i, j=0;
	for(i=0; i<s.size();i++){
		if(isdigit(s[i]))ans[j++]=s[i];
	}
	sort(ans, ans+j, cmp);
	for(i=0; i<j;i++){
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
} 
