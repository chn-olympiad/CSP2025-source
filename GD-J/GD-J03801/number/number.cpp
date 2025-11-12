#include<bits/stdc++.h>
using namespace std;
int a[1000010],n=0;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[n]=s[i]-'0';
			n++;
		}
	}
	sort(a,a+n);
	reverse(a,a+n);
	for(int i=0;i<n;i++) cout<<a[i];
	return 0;
}
