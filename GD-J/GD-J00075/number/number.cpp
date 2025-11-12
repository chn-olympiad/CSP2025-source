#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6+10;
string s;
int a[maxn],t,l;
bool b;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[++t]=s[i]-'0';
	sort(a+1,a+t+1);
	for(int i=t;i>=1;i--)cout<<a[i];
	return 0;
}
