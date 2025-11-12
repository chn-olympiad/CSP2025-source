#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll num[1000005],top;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>s;
	ll n=s.size();
	for(ll i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9')
			num[top++]=long(s[i]-'0');
	}
	sort(num,num+top);
	for(ll i=top-1;i>=0;i--)
		cout<<num[i];
	
	return 0;
} 
