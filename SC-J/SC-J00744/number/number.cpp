#include<bits/stdc++.h>
using namespace std;

string s;
int a[10];

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	memset(a,0,sizeof(a));
	for(int i=0; i<s.size(); ++i) {
		if(s[i]>='0' && s[i]<='9') {
			int number=s[i]-'0';
			++a[number];
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]!=0){
			for(int j=1;j<=a[i];++j){
				cout << i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}