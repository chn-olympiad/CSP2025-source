#include <bits/stdc++.h>
using namespace std;
const int maxn=1000003;
string s;
int a[maxn],al=0;
int main(void){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[al++]=s[i]-'0';
		}
	}
	sort(a,a+al);
	for(int i=al-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
