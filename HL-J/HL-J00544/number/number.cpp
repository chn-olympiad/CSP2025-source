#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(int i = 1;i <= 9;i++){
		if(i = s[1]){
			cout << i << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}