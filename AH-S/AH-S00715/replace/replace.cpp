#include <bits/stdc++.h>
#define int long long
using namespace std;
map<string,int> ms;
map<string,string> mp;
int n,q,sum;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s,t;
		cin>>s>>t;
		mp[s]=t;
		ms[s]=1;
	}
	for(int i=1;i<=q;i++){
		string s,t;
		sum=0;
		cin>>s>>t;
		int len=s.size();
		s=" "+s;
		for(int i=1;i<=len;i++){
			string p="";
			for(int j=i;j<=len;j++){
				p=p+s[j];
				if(ms[p]){
					if(s.substr(1,i-1)+mp[p]+s.substr(j+1,len-j)==t){
						sum++;
					}
				}
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}
