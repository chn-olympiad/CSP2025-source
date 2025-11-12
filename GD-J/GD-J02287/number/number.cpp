#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
string s;
ll a[N],sum;
bool cmp(ll x,ll y)
{
	return x>y;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')a[++sum]=s[i]-'0';
	}
	sort(a+1,a+1+sum,cmp);
	for(int i=1;i<=sum;i++)
	{
		cout<<a[i];
	}
	return 0;
} 
