//手握日月摘星辰，世间无我这般人 

#include<bits/stdc++.h>
using namespace std;

string s;
int a[1000090],x = 1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int l = s.length();
	for(int i = 0;i < l;i++){
		if(s[i] >= '0' &&s[i] <= '9'){
			a[x] = int (s[i] - '0');
			x++;
		}
	}
	x--;
	sort(a + 1,a + 1 + x);
	for(int i = x;i >= 1;i--){
		cout << a[i];
	}
	return 0;
} 
