#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >>s;
	int o=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			o++;
			a[o]=int(s[i]-'0');
		}
	}
	sort(a+1,a+1+o);
	for(int i=o;i>=1;i--){
		cout <<a[i];
	}
	return 0;
} 
