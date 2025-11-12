#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],z=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			z++;
			a[z]=s[i]-'0';
		}
	}
	sort(a+1,a+z+1);
	for(int i=z;i>=1;i--) cout<<a[i];
	return 0;
}
