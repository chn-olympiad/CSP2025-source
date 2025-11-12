#include<bits/stdc++.h>
using namespace std;
int a[1000005];
string s;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	for(int i = 0; i < len; i++){
		//if(s[i] < 'a') q.push(s[i] - '0');
		if(s[i] < 'a') a[++a[0]] = s[i]-'0';
	}
	sort(a+1, a+a[0]+1, greater<int>());
	//while(!q.empty()){
	//	int sum = q.top();
	//	cout << sum;
	//	q.pop();
	//}
	for(int i = 1; i <= a[0]; i++){
		cout << a[i];
	}
	cout << endl;
	return 0;
}
