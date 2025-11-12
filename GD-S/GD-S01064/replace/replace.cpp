#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,q;
pair<string,string>str[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++)cin>>str[i].first>>str[i].second;
	while(q--){
		string c,b;
		cin>>c>>b;
		int cnt=0;
		for(int i=1;i<=n;i++){
			string a=c;
			if(a.find(str[i].first)==-1)continue;
			int d=a.find(str[i].first);
			for(int j=0;j<str[i].first.size();j++)a[j+d]=str[i].second[j];
			cnt+=(a==b);
		}
		printf("%lld\n",cnt);
	}
	return 0;
}
