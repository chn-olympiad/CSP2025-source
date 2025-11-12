#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int v=0;
	int a[100000];
	cin >> s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[v]=s[i]-'0';
			v++;
		}
	}	
	sort(a,a+v,cmp);
	for(int i=0;i<v;i++){
		cout << a[i];
	}
	return 0;
}
