#include<bits/stdc++.h>
using namespace std;
bool cmp(int a, int b){
	return a > b;
	}
int a[1000005];
string s;
int main(){
freopen("number.in", "r", stdin);
freopen("number.out", "w", stdout);
cin >> s;
int p = 1;
for(int i = 0; i < s.size(); i++){
    if(s[i] >= '0' && s[i] <= '9'){
        a[p] = (s[i] - '0');
        p++;
	}
}
sort(a + 1, a + p + 1, cmp);
for(int i = 1; i < p; i++){
     cout << a[i];
}
return 0;
}
