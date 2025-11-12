#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000000],ind;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[ind]=s[i]-'0';
			ind++;
		}
	}
	sort(a,a+ind);
	for(int i=ind-1;i>=0;i--){
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
