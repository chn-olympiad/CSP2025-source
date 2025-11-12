#include <bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int c=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
			if(s[i]>='0'&&s[i]<='9'){
					a[c]=s[i];
					c++;
			}
	}
	for(int i=0;i<c-2;i++){
			for(int j=i+1;j<c-1;j++){
				if(a[i]<a[j]){
					sort(a[i],a[j]);
				}
			}
	}
	for(int i=0;i<c-1;i++){
			cout<<a[i];
	}
	return 0;
}
