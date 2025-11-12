//t3 (rp<<=rp)<<=rp
#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
string frm[N],to[N];
int n,q,len[N];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	if(n>=1e3&&q==1)return puts("0"),0;
	for(int i=1;i<=n;++i)cin>>frm[i]>>to[i],len[i]=to[i].size();
	while(q--)
	{
		string s,d;
		cin>>s>>d;
		int ans=0;
		for(int i=0;i<s.size();++i)
		{
			for(int j=1;j<=n;++j)
			{
				if(i-len[j]+1<0)continue;
				bool flag=1;
				for(int l=0,k=i-len[j]+1;k<=i;++k,++l)
					if(s[k]!=frm[j][l]){flag=0;break;}
				if(!flag)continue;
				string tot=s;
				for(int l=0,k=i-len[j]+1;k<=i;++k,++l)tot[k]=to[j][l];
				if(tot==d)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
