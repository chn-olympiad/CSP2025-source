#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n[s.size()],t=s.size();
	for(int i=0;i<t;i++){
		if(s>="0"&&s<="9")n[i]=s[i];
	}
	for(int i=0;i<t;i++){
		for(int j=0;j<t;j++){
			if(n[i]<n[j])swap(n[i],n[j]);
		}
	}
	for(int i=0;i<t;i++)cout<<n[i]-48;
	return 0;
}
