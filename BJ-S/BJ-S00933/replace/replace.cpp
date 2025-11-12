#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,q,p1[N];
string s1[N],s2[N],t1,t2,y3,y2;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i)
	{
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;++i)
	{
		int qz=0,hz=0,cnt=0;
		cin>>t1>>t2;
		for(;qz<t1.size();++qz) if(t1[qz]!=t2[qz]) break;
		for(;hz<t1.size();++hz) if(t1[t1.size()-hz-1]!=t2[t2.size()-hz-1]) break;
		for(int j=1;j<=n;++j)
		{
			if(s1[j].size()<t1.size()-qz-hz) continue;
			y3=s1[j]+" "+t1,y2=s2[j]+" "+t2;
			for(int k=1;k<y3.size();++k)
			{
				int p=p1[k-1];
				while(p!=0&&(y3[p]!=y3[k]||y2[p]!=y2[k])) p=p1[p-1];
				if(y3[p]==y3[k]&&y2[p]==y2[k]) p1[i]=p+1;
			}
			for(int k=0;k<y3.size();++k) if(s1[j].size()==p1[k]&&k>=n-hz) cnt++;
		}
		cout<<cnt<<'\n';
	}
	return 0;
}