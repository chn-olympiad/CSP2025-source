#include <bits/stdc++.h>
using namespace std;
string s;
string a[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
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
		for(int j=i+1;j<l;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=0;i<l;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
