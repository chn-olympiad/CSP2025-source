#include<bits/stdc++.h>
using namespace std;
const long long base=13331,mod=1000000007;
int n,q,lf,rt;
long long hash1[5000010],hash2[5000010],pw[5000010];
string s1,s2,t1,t2;
long long jqh1[500010],jqh2[500010],chh1,chh2,alch1,alch2,ans;
long long hw1[500010],hw2[500010];
int l[500010],r[500010],len[500010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	pw[0]=1;
	for(int i=1;i<=5000000;i++) pw[i]=pw[i-1]*base%mod;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		len[i]=s1.size();
		for(int i=0;i<s1.size();i++)
		{
//			if(i==0) hash1[i+1]=s1[i]%mod;
			hash1[i+1]=(hash1[i]*base%mod+s1[i]%mod)%mod;
//			if(i==0) hash2[i]=s2[i]%mod;
			hash2[i+1]=(hash2[i]*base%mod+s2[i]%mod)%mod;
		}
		hw1[i]=hash1[s1.size()];
		hw2[i]=hash2[s2.size()];
		for(int i=0;i<s1.size();i++)
		{
			if(s1[i]!=s2[i])
			{
				lf=i+1;
				break;
			}
		}
		for(int i=s1.size()-1;i>=0;i--)
		{
			if(s1[i]!=s2[i])
			{
				rt=i+1;
				break;
			}
		}
		if(lf==s1.size()&&rt==1) lf=1,rt=s1.size();
		jqh1[i]=(hash1[rt]-hash1[lf-1]*pw[rt-lf+1]%mod+mod)%mod;
		jqh2[i]=(hash2[rt]-hash2[lf-1]*pw[rt-lf+1]%mod+mod)%mod;
		l[i]=lf-1,r[i]=s1.size()-rt;
//		cout<<len[i]<<" "<<l[i]<<" "<<r[i]<<" "<<jqh1[i]<<" "<<jqh2[i]<<" "<<hw1[i]<<" "<<hw2[i]<<'\n';
	}
//	cout<<'\n';
	while(q--)
	{
		ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			cout<<0<<'\n';
			continue;
		}
		for(int i=0;i<t1.size();i++)
		{
//			if(i==0) hash1[i+1]=s1[i]%mod;
			hash1[i+1]=(hash1[i]*base%mod+t1[i]%mod)%mod;
//			if(i==0) hash2[i]=s2[i]%mod;
			hash2[i+1]=(hash2[i]*base%mod+t2[i]%mod)%mod;
		}
		
		for(int i=0;i<t1.size();i++)
		{
			if(t1[i]!=t2[i])
			{
				lf=i+1;
				break;
			}
		}
		for(int i=t1.size()-1;i>=0;i--)
		{
			if(t1[i]!=t2[i])
			{
				rt=i+1;
				break;
			}
		}
		if(lf==t1.size()&&rt==1) lf=1,rt=t1.size();
		
		chh1=(hash1[rt]-hash1[lf-1]*pw[rt-lf+1]%mod+mod)%mod;
		chh2=(hash2[rt]-hash2[lf-1]*pw[rt-lf+1]%mod+mod)%mod;
//		cout<<lf<<" "<<rt<<" "<<chh1<<" "<<chh2<<" "<<"\n\n";
		for(int i=1;i<=n;i++)
		{
			if(len[i]>t1.size()) continue;
			if(chh1==jqh1[i]&&chh2==jqh2[i])
			{
				alch1=(hash1[rt+r[i]]-hash1[lf-l[i]-1]*pw[(rt+r[i])-(lf-l[i])+1]%mod+mod)%mod;
				alch2=(hash2[rt+r[i]]-hash2[lf-l[i]-1]*pw[(rt+r[i])-(lf-l[i])+1]%mod+mod)%mod;
//				cout<<lf-l[i]<<" "<<rt+r[i]<<" "<<alch1<<" "<<alch2<<'\n';
				if(alch1==hw1[i]&&alch2==hw2[i])
				{
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
3 2
aaa bbb
xaaax xbbbx
axaaax axbbbx
wwaaawww wwbbbwww
kaxaaaxw kaxbbbxw
*/
