#include<bits/stdc++.h>
#define int long long
using namespace std;
string ans,s;
int a[1000005],cnt;
bool flag;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;s.size()>i;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[++cnt]=s[i]-'0';
	sort(a+1,a+1+cnt);
	for(int i=cnt;1<=i;i--)		
		ans+=a[i]+'0';
	for(int i=1;cnt>=i;i++)
		if(a[i]!=0)
			flag=1;
	if(flag==0) ans="0";			
	cout<<ans;	 
	return 0; 
} 