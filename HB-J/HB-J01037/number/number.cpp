#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(ll x,ll y)
{
    if(x>y) return true;
    return false;
}
int main()
{
	freopen("number4.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	ll l=s.size();
	ll bbb[l+1];
	for(ll i=0;i<l;i++)
	{
		if(s[i]=='0' || s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9')
		{
			bbb[i]=(int(s[i])-48);
		}
		else bbb[i]='a';
	}
	sort(bbb,bbb+l,cmp);
	for(ll i=0;i<l;i++)
	{
		if(bbb[i]!='a') cout<<bbb[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
