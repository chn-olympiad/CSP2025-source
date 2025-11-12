#include<bits/stdc++.h>
#define int long long
using namespace std;
int fdh[1000005];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int f=1;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9'){
			fdh[f]=s[i]-'0';
			f++;
		}
	sort(fdh+1,fdh+f);
	for(int i=f-1;i>=1;i--) cout<<fdh[i];
	return 0;
} 