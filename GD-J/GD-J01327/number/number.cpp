#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>s;
	n=s.size();
	s=" "+s;
	for(int i=1;i<=n;i++)
		if(s[i]>='0'&&s[i]<='9')a[s[i]-'0']++;
	bool k=true;
	for(int i=9;i>=0;i--)
	{
		if(i==0&&a[i]>0&&k){
			cout<<0;
			return 0;
		}
		if(a[i])k=false; 
		while(a[i]--)cout<<i;
	}
	return 0;
} 
