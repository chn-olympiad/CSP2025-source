#include <bits/stdc++.h>
using namespace std;
string s;
int j;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='1'&&s[i]<='9'){
			a[++j]=s[i]-'0';
		}
	}
	sort(a+1,a+j+1);
	for(int i=j;i>0;i--) cout<<a[i];
	return 0;
}
