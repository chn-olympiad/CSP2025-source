#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	vector<char> b;
	cin >>a;
	for (int i = 0;i < 1000000;i++){
		if (a[i] == '0' or a[i] == '1' or a[i] == '2' or a[i] == '3' or a[i] == '4' or a[i] == '5' or a[i] == '6' or a[i] == '7' or a[i] == '8' or a[i] == '9'){
			char c = a[i];
			b.push_back(c);
			}
		}
	sort(b.begin(),b.end());
	for (int i = 0;i < b.size();i++){
		cout <<b[i];
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
