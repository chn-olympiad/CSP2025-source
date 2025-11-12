#include<bits/stdc++.h>
#include<vector>
#define int long long
#define uint unsigned long long
using namespace std;
bool Mst;
const int N=2e5+10,M=5e6+10;
int n,q;
int ls1[N],ls2[N],lt1,lt2;
string s1[N],s2[N];
string t1,t2;
uint ht1[M],ht2[M];

const int H=114514123;
uint ph[M+10];
vector<uint> hs1[N],hs2[N];
uint hs3[N],hs4[N],hs5[N];
int ls4[N],ls5[N];
/*
if s1=a+b+c,s2=a+d+c
has
s3=b+d,s4=a,s5=c
*/

void solve1()
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=lt1-ls1[i];j++)
		{
			if(j && t1[j-1]!=t2[j-1]) break;
			if(j<lt1-ls1[i])
			{
				if((ht1[lt1]-ht1[j+ls1[i]])!=(ht2[lt2]-ht2[j+ls1[i]])) continue;
			}
			if((ht1[j+ls1[i]]-ht1[j])!=hs1[i][ls1[i]]*ph[j]) continue;
			if((ht2[j+ls2[i]]-ht2[j])!=hs2[i][ls2[i]]*ph[j]) continue;
			ans++;
		}
	}
	cout<<ans<<"\n";
}

void solve2()
{
	int ans=0;
	int l=0,r=lt1+1;
	while(l<lt1 && t1[l]==t2[l]) l++;
	while(r>1 && t1[r-2]==t2[r-2]) r--;
	if(l>=r-1)
	{
		cout<<"0\n";
		return;
	}
	uint hh=0;
	int p=r-l-1;
	for(int i=l+1;i<r;i++) hh+=ph[i-l-1]*t1[i-1];
	for(int i=l+1;i<r;i++)
	{
		hh+=ph[i-l-1+p]*t2[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		if(hs3[i]!=hh) continue;
		if(ls4[i]>l || ls5[i]>(lt1-r+1)) continue;
		if((ht1[l]-ht1[l-ls4[i]])!=hs4[i]*ph[l-ls4[i]]) continue;
		//l-ls4+1~l
		if((ht1[r+ls5[i]-1]-ht1[r-1])!=hs5[i]*ph[r-1]) continue;
		//r~r+ls5-1
		ans++;
	}
	cout<<ans<<"\n";
}

bool Med;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	ph[0]=1;
	for(int i=1;i<=M;i++)
	{
		ph[i]=ph[i-1]*H;
	}
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i];
		cin>>s2[i];
		ls1[i]=s1[i].size();
		ls2[i]=s2[i].size();
		hs1[i].resize(ls1[i]+1);
		hs2[i].resize(ls2[i]+1);
		for(int j=1;j<=ls1[i];j++)
		{
			hs1[i][j]=hs1[i][j-1]+ph[j-1]*s1[i][j-1];
		}
		for(int j=1;j<=ls2[i];j++)
		{
			hs2[i][j]=hs2[i][j-1]+ph[j-1]*s2[i][j-1];
		}
		int l=0;
		while(l<ls1[i] && s1[i][l]==s2[i][l]) l++;
		for(int j=1;j<=l;j++)
		{
			hs4[i]+=ph[j-1]*s1[i][j-1];
		}
		int r=ls1[i]+1;
		while(r>1 && s1[i][r-2]==s2[i][r-2]) r--;
		for(int j=r;j<=ls1[i];j++)
		{
			hs5[i]+=ph[j-r]*s1[i][j-1];
		}
		ls4[i]=l,ls5[i]=ls1[i]-r+1;
		int p=r-l-1;
		for(int j=l+1;j<r;j++)
		{
			hs3[i]=hs3[i]+ph[j-l-1]*s1[i][j-1];
		}
		for(int j=l+1;j<r;j++)
		{
			hs3[i]=hs3[i]+ph[j-l-1+p]*s2[i][j-1];
		}
	}
	for(int i=1;i<=q;i++)
	{
//		if(i%100==0) cerr<<i<<endl;
		cin>>t1;
		cin>>t2;
		lt1=t1.size();
		lt2=t2.size();
		if(lt1!=lt2)
		{
			cout<<"0\n";
		}
		else
		{
			for(int i=1;i<=lt1;i++)
			{
				ht1[i]=ht1[i-1]+ph[i-1]*t1[i-1];
			}
			for(int i=1;i<=lt2;i++)
			{
				ht2[i]=ht2[i-1]+ph[i-1]*t2[i-1];
			}
//			if(lt1<=2000 && q>=2000)
//			{
//				solve1();
//			}
//			else
//			{
				solve2();
//			}
		}
	}
	cout<<endl;
}
/*
replace

g++ replace.cpp -o replace.exe
g++ check.cpp -o check.exe
./replace.exe
./check.exe

*/
