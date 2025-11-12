#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	auto geti=[]{
		int res=0;
		char ch;
		while(isspace(ch=getchar()));
		res=ch^48;
		while(isgraph(ch=getchar()))
			res=res*10+(ch^48);
		return res;
	};
	static int n=geti(),k=geti(),s[500005];
	for(int i=1;i<=n;i++)
		s[i]=geti()^s[i-1];
	int ans=0,last=0;
	for(int i=1;i<=n;i++)
		for(int j=i;j>last;j--)
			if((s[i]^s[j-1])==k)
				++ans,last=i;
	cout<<ans<<'\n';
	return 0;
}