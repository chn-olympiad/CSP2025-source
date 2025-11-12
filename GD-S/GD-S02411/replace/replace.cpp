#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
const int M=5e6+5;
const int base1=103,base2=1e9+7;
int n,m,q,len[N];
string s1[N],s2[N];
unsigned ll p[M][3],h1[N][3],h2[N][3];
unsigned ll g1[M][3],g2[M][3];
void init(){
	p[0][0]=p[0][1]=1;
	for(int i=1;i<=5e6;i++)
	{
		p[i][0]=p[i-1][0]*base1;
		p[i][1]=p[i-1][1]*base2;
	}
}
unsigned ll calc1(int l,int r,int opt){
	return g1[r][opt]-g1[l-1][opt]*p[r-l+1][opt];
}
unsigned ll calc2(int l,int r,int opt){
	return g2[r][opt]-g2[l-1][opt]*p[r-l+1][opt];
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	init();
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		len[i]=s1[i].size();
		s1[i]=' '+s1[i];
		s2[i]=' '+s2[i];
		for(int j=1;j<=len[i];j++)
		{
			h1[i][0]=h1[i][0]*base1+(s1[i][j]-'a');
			h2[i][0]=h2[i][0]*base1+(s2[i][j]-'a');
			h1[i][1]=h1[i][1]*base2+(s1[i][j]-'a');
			h2[i][1]=h2[i][1]*base2+(s2[i][j]-'a');
		}
	}
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		m=t1.size();
		t1=' '+t1;
		t2=' '+t2;
		for(int i=1;i<=m;i++){
			g1[i][0]=g1[i-1][0]*base1+(t1[i]-'a');
			g2[i][0]=g2[i-1][0]*base1+(t2[i]-'a');
			g1[i][1]=g1[i-1][1]*base2+(t1[i]-'a');
			g2[i][1]=g2[i-1][1]*base2+(t2[i]-'a');
		}
		int lt=m+1,rt=0;
		for(int i=1;i<=m;i++)
		{
			if(t1[i]!=t2[i]){
				lt=min(lt,i);
				rt=max(rt,i);
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			if(len[i]<rt-lt+1) continue;
			for(int j=max(1,rt-len[i]+1);j<=min(lt,m-len[i]+1);j++)
			{
				int x=j,y=j+len[i]-1;
				if(calc2(x,y,0)!=h2[i][0]) continue;
				if(calc1(x,y,0)!=h1[i][0]) continue;
				if(calc2(x,y,1)!=h2[i][1]) continue;
				if(calc1(x,y,1)!=h1[i][1]) continue;
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
*/
