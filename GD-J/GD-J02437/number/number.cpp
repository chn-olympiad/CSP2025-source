#include<bits/stdc++.h> 
using namespace std;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;long long z=0,a[z];
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[z++]=(int)(s[i]-'0');
		}
	}sort(a,a+z);
	for(int i=z-1;i>=0;i--){
		cout << a[i];
	}
	return 0;
}
