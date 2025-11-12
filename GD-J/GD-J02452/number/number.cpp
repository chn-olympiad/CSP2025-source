#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
int a[N];
bool rule(int a, int b){
	return a > b;
}
int main(){
	//task number (Accepted)
	freopen("number4.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int t = s.size();
	if (t == 1){
		cout << s;
		return 0;
	}
	int cnt = 0;
	for (char i : s){
		if (i >= '0' && i <= '9'){
			a[cnt] = (i-'0');
			cnt++;
		}
		else t--;
	}
	sort(a, a+t, rule);
	int i = 0;
	while (cnt--){
		printf("%.d",a[i]);
		if(a[i] == 0) cout << 0;
		i++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
