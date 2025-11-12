#include<bits/stdc++.h>
using namespace std;
string s;
long long a[10],i;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i=0;i<s.size();i++)if(s[i]>='0'&&s[i]<='9')a[int(s[i]-'0')]++;
	for(i=9;i>=0;i--)while(a[i]--)printf("%lld",i);
	return 0;
}
