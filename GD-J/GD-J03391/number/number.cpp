#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int k = 0;
	int b[500005] = {0};
	for(int i = 0; i < s.size(); i++){
		if((int)s[i] <= 57 && (int)s[i] >= 48){
			k++;
			b[k] = (int)s[i] - 48;
		}
	}
	sort(b+1,b+k+1);
	for(int i = k; i >= 1; i--){
		cout << b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
