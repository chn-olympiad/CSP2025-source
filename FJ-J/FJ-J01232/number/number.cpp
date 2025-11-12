#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
string s;
int a[maxn];
bool cmp(int a , int b){
	return a > b;
} 

int main(){
	freopen ("number.in" , "r" , stdin);
	freopen ("number.out" , "w" , stdout);
    cin >> s;
	int l = s.size();
	int a_ = 0;
	if (l == 1){
		if (s[0] >= '0' && s[0] <= '9'){
			cout << s[0];
			return 0;
		}
	}
		
	else{
		for (int i = 0 ; i < l ; i++){
			if (s[i] >= '0' && s[i] <= '9'){
				a_++;
				a[a_] = s[i] - '0';
			}
		}
	}
	sort (a + 1 , a + a_ + 1 , cmp);
	for (int i = 1 ; i <= a_ ; i ++) printf ("%d" , a[i]);
	return 0;
}


