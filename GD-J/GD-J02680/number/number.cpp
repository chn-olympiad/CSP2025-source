#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1001],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++)
		if(isdigit(s[i]))
			a[++cnt]=s[i]-48;
	sort(a+1,a+cnt+1);
	for(long long i=cnt;i>=1;i--){
		cout<<a[i];
		if(a[i]==0&&i==cnt) break;
	}
	return 0;
}
