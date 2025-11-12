#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+5,P=1e9+9;

int n,q;
string s1,s2;
map<pair<string,string>,int> mp;


const int NN=5e6+5;
int p[NN],h[NN],h2[NN],ha1[NN],ha2[NN],ll[N],rr[N],len[N];

int get1(int l,int r)
{
	return ((h[r]-h[l-1]*p[r-l+1])%P+P)%P;
}
int get2(int l,int r)
{
	return ((h2[r]-h2[l-1]*p[r-l+1])%P+P)%P;
}

/*
4 1
xabcx xadex
ab cd
bc de
aa bb
aaaa bbbb
*/
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		mp[{s1,s2}]=1;
		ll[i]=-1;
		len[i]=s1.length();
		for(int j=0;j<len[i];j++){
			ha1[i]=(ha1[i]*13331+s1[j]-'a')%P;
			ha2[i]=(ha2[i]*13331+s2[j]-'a')%P;
			if(s1[j]!=s2[j] && ll[i]==-1) ll[i]=j;
			if(s1[j]!=s2[j]) rr[i]=j; 
		}
		ll[i]++,rr[i]++;
	}
	if(q==1){
		string c1,c2;
		cin>>c1>>c2;
		int n1=c1.length(),n2=c2.length();
		if(n1!=n2) return cout<<0,0;
		for(int i=1;i<=n1;i++) s1[i]=c1[i-1],s2[i]=c2[i-1];
		int l=-1,r=-1;
		for(int i=1;i<=n1;i++){
			if(s1[i]!=s2[i] && l==-1) l=i;
			if(s1[i]!=s2[i]) r=i; 
		}
		p[0]=1;
		for(int i=1;i<=5000000;i++) p[i]=p[i-1]*13331%P;
		for(int i=1;i<=n1;i++){
			h[i]=(h[i-1]*13331+s1[i]-'a')%P;
			h2[i]=(h2[i-1]*13331+s2[i]-'a')%P;
		} 
		int ans=0;
		for(int i=1;i<=n;i++){
			if(rr[i]-ll[i]!=r-l) continue;
			if(ha1[i]==get1(l-ll[i]+1,l-ll[i]+len[i]) && ha2[i]==get2(l-ll[i]+1,l-ll[i]+len[i])){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
		while(q--){
		cin>>s1>>s2;
		int n1=s1.length(),n2=s2.length(),ans=0;
		if(n1!=n2){
			cout<<0<<"\n";
			continue;
		}
		int l=-1,r=-1;
		for(int i=0;i<n1;i++){
			if(s1[i]!=s2[i] && l==-1) l=i;
			if(s1[i]!=s2[i]) r=i; 
		}
		for(int i=0;i<=l;i++){
			string ss1="",ss2="";
			for(int j=i;j<n1;j++){
				ss1+=s1[j];
				ss2+=s2[j];
				if(j>=r) ans+=mp[{ss1,ss2}];
			}
		}
		cout<<ans<<"\n";
		}
	
	return 0;
}

