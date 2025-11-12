#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000005];
bool cmp(int x,int y){
	return x>y;
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cnt=0;
	for(int i=0;i<=1000005;i++) a[i]=-1;
	for(int i=0;i<=s.size();i++)
	{
		if('0'<=s[i] and s[i]<='9')
		{
			a[i]=s[i]-48;
			if(s[i]=='0') cnt++;
			}  
	}
	string d;
	sort(a,a+s.size(),cmp);
	for(int j=0;j<=10000005;j++){
		if(a[j]==-1) break;
		d+=a[j]+48;
	}
	cout<<d<<"\n";
	return 0;
}
