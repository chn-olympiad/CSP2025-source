#include <bits/stdc++.h>
using namespace std;
const int N=1e6+1;
string s;
int a[N],id;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')a[++id]=s[i]-'0';
	}
	sort(a+1,a+1+id);
	for(int i=id;i>=1;i--)cout<<a[i];
	return 0;
}
