#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
string s;
int arr[N];
int pt = 0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (int i = 0;i < s.size();i++){
		if (s[i] >= '0' && s[i] <= '9'){
			arr[pt] = s[i] - '0';
			pt++; 
		}
	}
	sort(arr,arr+pt);
	for (int i = pt-1;i >=0;i--){
		cout << arr[i];
	}
	return 0;
} 
