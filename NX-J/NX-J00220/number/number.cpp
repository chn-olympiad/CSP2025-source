#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,s2={0};
	cin>>s;
	int n=s.size();
	for(int i=1;i<=n;i++){
		if(isdigit(s[i])){
			s2+=s[i];
		}
	}
	int n1=s2.size();
	for(int i=1;i<=n1;i++){
		for(int j=i+1;j<=n1;j++){
			if(s2[j]>s[i])swap(s[i],s[j]);
		}
	}
	cout<<s2;
	return 0;
}
