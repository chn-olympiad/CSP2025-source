#include<iostream>
using namespace std;
const int maxn = 1e6+5;
long long a[maxn];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s, s1;
	cin >> s;
	long long n = s.size();
	for(int i = 0; i <= n; i++){
		if(s[i]>='0'&&s[i]<='9'){
			s1+=s[i];
		}
	}
	for(int i = 0; i < s1.size(); i++){
		a[i] = int(s1[i]);
	}
	n = s1.size();
	long long x;
	for(int i = 0; i <= n; i++){
		for(int j = i; j <= n; j++){
			if(a[i]<a[j]){
				x = a[i];
				a[i] = a[j];
				a[j] = x;
			}
		}
	}
	for(int i = 0; i <= s1.size(); i++){
		cout << char(a[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
