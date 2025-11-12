#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1002000],l,i;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[++l]=s[i]-'0';
	}
	sort(a+1,a+1+l);
	for(i=l;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 
