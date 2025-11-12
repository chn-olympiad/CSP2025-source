#include<bits/stdc++.h>
using namespace std;

char arr[1000003];

bool cmp(int a, int b){
	return a>b;
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int l=0;
	for (int i=0; i<s.size(); ++i){
		if (s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9' || s[i]=='0'){	
			arr[l]=s[i];
			l++;
		}
	}
	sort(arr, arr+l, cmp);
	for (int i=0; i<l; ++i){
		cout << arr[i];
	}
	return 0; 
}
