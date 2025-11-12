#include<bits/stdc++.h>
using namespace std;

int cnt=0,t[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int len =s.length();
	for(int i=0;i<len;i++){
		if(isdigit(s[i])){
			t[int(s[i])-48]++;
			cnt++;
		}
	}
	for(int i=9;i>=0;i--){
		int x = t[i];
		while(x){
			cout << i;
			x--;
		}
	}
	return 0;
}
