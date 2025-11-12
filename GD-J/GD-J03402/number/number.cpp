#include <bits/stdc++.h>
using namespace std;
int a[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	s = ' '+s;
	int n = s.size();
	for (int i=1;i<=n;i++){
		if (s[i] >= '0' && s[i] <= '9')a[s[i]-'0']++;
	}//O(n) 
	for (int i=9;i>=0;i--)
	{
		if (a[i] > 0){
			for (int j=1;j<=a[i];j++)cout << i;
		}
	}
	//O(n)
	return 0;
} 
