#include<bits/stdc++.h>
using namespace std;
long long a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<(int)(s.size());i++){
		if('0'<=s[i]&&s[i]<='9')
			a[(int)(s[i]-'0')]++;
	}
	for(int i=9;i>=0;i--)
		for(int j=a[i];j>=1;j--)
			cout<<i;
	return 0;
}
