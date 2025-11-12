#include <bits/stdc++.h>
using namespace std;
string s;
int c[100100];
int n = 1;

bool cmp(int a,int b){
	return a > b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			c[n] = s[i] - '0';
			n++;
		}
	}
	sort(c+1,c+n+1,cmp);
	int t = n;
	for(int i=1;i<t;i++){
		cout << c[i];
	}
	return 0;
} 
