#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin >> a;
	int l=a.length();
	int b[15]={};
	for (int i=0;i<l;i++){
		char c=a[i];
		if (c>='0'&&c<='9')
			b[c-'0']++;
	}
	for (int i=9;i>=0;i--){
		for (int j=0;j<b[i];j++)
			cout << i;
	}
	cout << endl;
	
	return 0;
}
