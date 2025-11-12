#include<bits/stdc++.h>
using namespace std;
string a[1000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	int l=s.size();
	if(l==1){
	cout<<s;
	return 0;
	}

for(int i=0;i<l;i++){
	if(s[i]<'a'&&s[i]>'z'&&s[i]<'A'&&s[i]>'z'){
		a[i]=s[i];
	}		
}
for(int i=0;i<l;i++){
	for(int j=0;j<l;j++){
		if(a[i]<a[j]){
			swap(a[i],a[j]);
		}
	}
	
}
for(int i=0;i<l;i++)
	cout<<a[i];
	return 0;
}


