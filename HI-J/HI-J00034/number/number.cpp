#include<bits/stdc++.h>
using namespace std;
string a;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i];
		}
	}
	for(int i=0;i<=s.size();i++){
		for(int i=0;i<=s.size();i++){
			if(a[i]<a[i+1]){
				swap(a[i],a[i+1]);
			}
		}
	}
	for(int i=0;i<=s.size();i++){
		cout<<a[i];
	}
	return 0;
}
