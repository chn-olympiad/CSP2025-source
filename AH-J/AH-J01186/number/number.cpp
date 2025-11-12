#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
string s,a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	LL len=s.size();
	for(LL i=0;i<len;i++){
		if(isdigit(s[i]))a+=s[i];
	}
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	cout<<a;
	return 0;
}
