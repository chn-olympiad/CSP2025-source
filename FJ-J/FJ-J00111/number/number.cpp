#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],l;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0; i <= s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			l++;
			a[l] = s[i];
		}
	}
	sort(a+1,a+1+l);
	for(int i = l; i >= 1; i--){
		cout << a[i] - 48;
	}
	return 0;
}
