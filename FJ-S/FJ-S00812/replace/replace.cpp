#include<bits/stdc++.h>
using namespace std;
typedef long long ljl;
const int N=2e5+5,L=5e6+5;
int n,q,ans;
string s[N][3],t[3];
int getid(string a,string b,int st)
{
	int lena=(int)a.size(),lenb=(int)b.size();
	if(a<b)return -1;
	for(int i=st;i+lenb-1<lena;++i)
	{
		int j=i,k=0;
		while(a[j]==b[k])
		{
			++j;++k;
			if(k==lenb-1)return i;
		}
	}
	return -1;
}
void Main()
{
	cin>>t[1]>>t[2];ans=0;
	int lent1=(int)t[1].size(),lent2=(int)t[2].size();
	if(lent1!=lent2)
	{
		cout<<0<<'\n';
		return;
	}
	for(int i=1;i<=n;++i)
	{
		int z=getid(t[1],s[i][1],0);
//		cout<<i<<' '<<z<<'\n';
		while(z!=-1)
		{
			string tmp="";
			for(int j=0;j<z;++j)tmp+=t[1][j];
			tmp+=s[i][2];
			tmp+=t[1].substr(z+(int)s[i][1].size(),(int)t[1].size());
//			cout<<i<<" "<<tmp<<'\n';
			if(tmp==t[2])++ans;
			z=getid(t[1],s[i][1],z+1);
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i)
		cin>>s[i][1]>>s[i][2];
	while(q--)
		Main();
	return 0;
}

