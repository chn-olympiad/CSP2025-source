#include<bits/stdc++.h> 
using namespace std;
const int N = 1e6+5;
string s;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int j = 1;
	for(int i = 0;i < s.length();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[j++] = s[i] - '0';		
		}
	}
	sort(a + 1,a + j,greater<int>());
	for(int i = 1;i < j;i++){
		cout << a[i];
	}
	return 0;
}
