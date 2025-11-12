#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[10000001];
bool cmp(int x,int y){
	return x>y;
}
signed main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	string s;
	int ans=0;
	cin>>s;
	int n=s.size();
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){a[ans]=s[i]-'0';ans++;}
	}
	sort(a,a+n,cmp);
	for(int i=0;i<ans;i++){
		cout<<a[i];
	}
}
