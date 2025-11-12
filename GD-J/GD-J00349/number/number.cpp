#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int a[10]{};
	for (int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			int l;
			l=int(s[i])-48;
			a[l]++;
		}
	}
	for (int i=9;i>=0;i--){
		while(a[i]){
			cout << i;
			a[i]--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
