#include<bits/stdc++.h>
using namespace std;
long long a[1000002];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long x=0,len;
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>=48&&s[i]<=57){
			x++;
			a[x]=int(s[i]-48);
		}
	}
	sort(a+1,a+x+1);
	for(int i=x;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
