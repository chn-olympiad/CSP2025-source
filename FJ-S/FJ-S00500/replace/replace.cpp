#include <bits/stdc++.h>
#define fr(x)\
	freopen(#x".in","r",stdin);\
	freopen(#x".out","w",stdout);

using std::cin;
typedef long long ll;
constexpr int N=2e5+114;
int n,q;
std::string s[N][2],t[2];

int main()
{
	fr(replace)
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
		s[i][0]=' '+s[i][0];
		s[i][1]=' '+s[i][1];
	}
	for(int i=1;i<=q;i++)
	{
		// fprintf(stderr,"%d\n",i);
		cin>>t[0]>>t[1];
		t[0]=' '+t[0],t[1]=' '+t[1];
		int ans=0,lt=t[0].size()-1;
		for(int j=1;j<=n;j++)
		{
			int ls=s[j][0].size()-1;
			for(int k=1;k+ls-1<=lt;k++)
			{
				// fprintf(stderr,"%d:%s %s\n%s %s\n\n",j,t[0].substr(k,ls).c_str(),s[j][0].substr(1).c_str(),(t[0].substr(1,k-1)+s[j][1].substr(1)+t[0].substr(k+ls)).c_str(),t[1].c_str());
				if(t[0].substr(k,ls)==s[j][0].substr(1)&&(t[0].substr(1,k-1)+s[j][1].substr(1)+t[0].substr(k+ls))==t[1].substr(1))
				{
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
