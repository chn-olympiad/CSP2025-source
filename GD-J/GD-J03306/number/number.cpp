#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+5;
string s; 
int l,a[N];
bool cmp(int x,int y){return x>y;}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')a[++l]=(s[i]-'0');
	}
	sort(a+1,a+l+1,cmp);
	for(int i=1;i<=l;i++)cout<<a[i];
	return 0;
}

