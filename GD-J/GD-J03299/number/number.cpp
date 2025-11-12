#include<bits/stdc++.h>
using namespace std;
int a[1000005];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>s;
	int num=0;
	for(int i=1;i<=s.length();i++){
		if(s[i-1]>='0'&&s[i-1]<='9'){
			a[++num]=s[i-1]-'0';
		}
	}
	sort(a+1,a+1+num);
	for(int i=num;i>=1;i--){
		cout <<a[i];
	}
	return 0;
}
