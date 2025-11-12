#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int b=s.size();
	int c[10]={0};
	for(int i=0;i<b;i++){
		if(s[i]>='0'&&s[i]<='9'){
			c[int(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(c[i]>0){
			for(int j=1;j<=c[i];j++){
				cout << i;
			}
		}
	}
	cout << endl;
	return 0;
}
