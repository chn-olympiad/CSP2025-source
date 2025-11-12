#include<bits/stdc++.h>
using namespace std;
int a[1000001], ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[ans] = int(s[i])-48;
			ans++;
		}
	}
	sort(a, a+ans);
	for(int i = ans-1; i >=0; i--)
	cout << a[i];
	return 0;
}