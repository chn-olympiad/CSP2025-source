#include <bits/stdc++.h>
using namespace std;
string s={},m={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int a=s.size();
	for(int i=0;i<a;i++){
		if(s[i]>='0'&&s[i]<='9'){
			m+=s[i];
		}
	}
	int A=m.size();
	for(int i=0;i<A;i++){
		for(int j=0;j<A;j++){
			if(m[i]>m[j]){
				swap(m[i],m[j]);
			}
		}
	}
	cout<<m;//All Check
	return 0;
}

