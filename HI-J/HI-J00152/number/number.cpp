#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int m=0;
	string s;
	cin >> s;
	long long a[100005]={};
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[m]=s[i]-'0';
			m++;
		}
	}
	sort(a,a+m); 
	for(int i=m-1;i>=0;i--){
		cout << a[i];
	}
	return 0;
}
