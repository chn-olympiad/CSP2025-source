#include <bits/stdc++.h>
using namespace std;

int a[1000005],t=0,e;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	e = s.size();
	for(int i=0;i<e;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[t] = s[i] - '0';
			t++;
		}
	}
	sort(a,a+t);
	for(int i=t-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
