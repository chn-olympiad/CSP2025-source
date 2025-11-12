#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long n = 0,a[N],middle = 0;
	bool si = false;
	cin >> s;
	for (int i = 0; i < s.length();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[n] = (s[i] - '0');
			n++;
		}
	}
	for (int j = 0;j < sqrt(n);j++){
		for (int i = 0;i < (n - 1);i++){
			if (a[i] < a[i + 1]){
				middle = a[i];
				a[i] = a[i + 1];
				a[i + 1] = middle;
				si = true;
			}
		}
		if (si == false){
			break;
		}
		si = false;
	}
	for (int i = 0;i < n;i++){
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
