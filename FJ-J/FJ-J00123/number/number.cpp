#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
string s;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size(),cnt=0,flag=0;
	for(int i=0;i<len;i++) {
		if(s[i]>='0' && s[i]<='9') {
			cnt++;
			a[cnt]=s[i]-'0';
			if(a[cnt]) flag=1;
		}
	}
	if(!flag)
	{
		cout<<0;
		return 0;
	}
	sort(a+1,a+1+cnt);
	for(int i=cnt;i>=1;i--) cout<<a[i];
	return 0;
}
