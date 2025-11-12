#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,b;
	long long c=0;
	getline(cin,s);
	string a[s.size()];
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[c]=s[i];
			c++;
		}
	}
	for(long long i=0;i<c;i++){
		if(i!=c){
			if(a[i]<a[i+1]){
				b=a[i];
				a[i]=a[i+1];
				a[i+1]=b;
			}
		}
		cout<<a[i];
	}
	return 0;
}
