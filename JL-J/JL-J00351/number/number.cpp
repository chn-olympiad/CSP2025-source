#include<bits/stdc++.h>
using namespace std;
int cnt=0,a[1000010];
map<char,int> mp;
char s[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=strlen(s);
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9') mp[s[i]]++;
	}
	for(auto i:mp){
		auto x=i;
		while(x.second){
			a[++cnt]=i.first-'0';
			x.second--;
		}
	}
	for(int i=cnt;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
