#include<bits/stdc++.h>
using namespace std;
int a[1000100],tot=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[tot]=s[i]-'0';
			tot++;
		}
	}
	sort(a+1,a+tot);
	for(int i=tot-1;i>=1;i--) cout<<a[i];
	cout<<endl;
	return 0;
}

