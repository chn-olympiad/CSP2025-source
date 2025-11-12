#include<bits/stdc++.h>
using namespace std;
const int L=1e6+1;
int n,a[L];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++) if(s[i]>='0'&&s[i]<='9') a[n++]=s[i]-'0';
	sort(a,a+n);
	bool number=0;
	if(a[n-1]==0) cout<<'0';
	else{
		for(int i=n-1;i>=0;i--) cout<<a[i];
	}
	cout<<endl; 
	return 0;
}