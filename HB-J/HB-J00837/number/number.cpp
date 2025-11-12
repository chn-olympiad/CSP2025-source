#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005],x=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(unsigned int i=0;i<=s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[x]=s[i]-'0';
			x++;
		}
	}
	x--;
	sort(a+1,a+x+1);
	for(int i=1;i<=x;i++) cout<<a[x-i+1];
	return 0;
}
