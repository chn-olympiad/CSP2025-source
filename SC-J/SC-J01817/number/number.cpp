#include<bits/stdc++.h>
using namespace std;

int h[10];
string s1;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w",stdout);
	cin >> s1;
	for (int i=0;i<s1.size();i++){
		if (isdigit(s1[i]))
			h[ s1[i]-'0' ]++;
	}
	for (int i=9;i>=0;i--){
		while(h[i]){
			cout << i;
			h[i]--;
		}
	}
	return 0;
}