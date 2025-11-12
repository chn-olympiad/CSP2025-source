#include<bits/stdc++.h>
using namespace std;

int const MAXN =1e6 + 5;
string s;
string s1;
int a[MAXN];
long long ans;

int main(){
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);	
	cin >> s;
	for(int i = 0; i <= MAXN; i++){
		a[i] = 0x3f3f3f3f;
	}
	for(int i = 0 ; i <= s.size()-1; i++){
		s[i] -= '0';
		if(s[i] >= 0 && s[i] <= 9)
		a[i] = s[i];
	    sort(a,a+i);
	}
for(int i = 0; i <= s.size(); i++){
	if(a[i] != 0x3f3f3f3f && a[i] != 0)
	ans += a[i] * pow(10 , i);
	else if(a[i]==0)
	ans *= 10;
}
	cout << ans;
}
    
