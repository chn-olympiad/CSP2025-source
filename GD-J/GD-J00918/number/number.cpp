#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
vector<int> a;
signed main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')  a.push_back(s[i]-'0');
	}
	sort(a.begin(),a.end(),greater<int>());
	if(a[0]==0)  printf("0");
	else  for(auto i:a)  printf("%lld",i);
	
	return 0;
}
