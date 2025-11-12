#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,a;
	cin >> s;
	if(s.size()==1){
	cout << s;	
	return 0;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')a+=s[i];
	}for(int i=0;i<a.size();i++){
		for(int j=i;j<a.size();j++){
			if(a[j]>=a[i])swap(a[i],a[j]);
		}
	}
	cout << a;
	return 0;
}