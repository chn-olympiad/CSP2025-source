#include<bits/stdc++.h>
using namespace std;
signed main(){
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int num[10]={};
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
	  if(s[i]>='0'&&s[i]<='9')
	    num[int(s[i])-48]++;
	for(int i=9;i>=0;i--)
	  for(int j=1;j<=num[i];j++)
	    cout<<i;
	return 0;
}
