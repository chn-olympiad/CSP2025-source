#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
string s,a[N];
string maxn;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	long long len = s.size();
	for(int i=0;i<len;i++){
		if(s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9'){
			if(len == 1){
				cout << s;
				return 0; 
			}
			a[i] += s[i];
		}
	}
	sort(a,a+len+1);
	for(int i=len;i>0;i--){
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
