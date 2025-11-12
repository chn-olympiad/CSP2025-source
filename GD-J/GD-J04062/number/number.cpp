#include<bits/stdc++.h>
using namespace std;
string s;
int n[1000000],nlen;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			n[nlen]=s[i]-'0';
			nlen++;
		}
	}
	sort(n+0,n+0+nlen);
	for(int i = nlen-1;i>=0;i--){
		cout << n[i];
	}
	cout <<endl;
	
	return 0;
} 
