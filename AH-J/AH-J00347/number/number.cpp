#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>s;
	int cnt=0,len=s.size();
	for(int i=0;i<len;i++)
		if(s[i]>='0'&&s[i]<='9') a[++cnt]=s[i]-'0';
	sort(a+1,a+1+cnt);
	for(int i=cnt;i;i--)
		cout<<a[i];
	return 0;
}
