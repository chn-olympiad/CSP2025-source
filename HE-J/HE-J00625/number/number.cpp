#include<bits/stdc++.h>
using namespace std;
string s,a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	char n[s.size()];
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9')a+=s[i];
	}
	for(int i=0;i<=s.size();i++){
		for(int j=0;j<=s.size();j++)
			if(a[j]<a[j+1])swap(a[j],a[j+1]);
	}
	cout<<a;
	return 0;
}
