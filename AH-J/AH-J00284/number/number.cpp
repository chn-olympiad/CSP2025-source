#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],sum;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0') a[++sum]=(int)s[i]-48;
	}sort(a+1,a+sum+1);
	for(int i=sum;i>=1;i--) cout<<a[i];
	return 0;
}
