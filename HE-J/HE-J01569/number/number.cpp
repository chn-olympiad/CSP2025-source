#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N];

bool cmp (int a1, int a2){
	if(a1 > a2) return true;
	return false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int j = 0;
	for(int i = 0; i < s.size(); i++){
		if(isdigit(s[i])){
			a[j] = s[i] - '0';
			j++;
		}
	}
	sort(a, a+j, cmp);
	for(int i = 0; i < j; i++){
		cout << a[i];
	}	
	return 0;
}
