#include <bits/stdc++.h>
using namespace std;
char a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i];
		}
	}
	sort(a,a+s.size());
	for(int i=1000004;i>=0;i--){
		if(a[i]>='0'&&a[i]<='9') cout<<a[i];
	}
	return 0;
}
