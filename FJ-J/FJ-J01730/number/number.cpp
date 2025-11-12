#include<bits/stdc++.h>
using namespace std;
string s,ans;
int a[1000005];
int b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++b]=int(s[i])-48;
		}
	}
	sort(a+1,a+1+b);
	for(int i=b;i>=1;i--) ans+=char(a[i]+48);
	cout<<ans;
	return 0;
}
