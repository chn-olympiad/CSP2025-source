#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
const int N=2e5+5,L=5e6+5;
int n,q;
string a[N],b[N],s,t;
int ad[N];
ull hs[N],ht[N];
ull rs[L],rt[L];
ull pw[L];
ull hashing(int l,int r,ull*f){
	return f[r]-f[l-1]*pw[r-l+1];
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		ad[i]=(int)b[i].size()-a[i].size();
		for(char c:a[i])hs[i]=hs[i]*131+c;
		for(char c:b[i])ht[i]=ht[i]*131+c;
	}
	pw[0]=1;
	for(int i=1;i<L;i++)pw[i]=pw[i-1]*131;
	while(q--){
		cin>>s>>t;
		for(int i=0,sz=s.size();i<sz;i++)rs[i+1]=rs[i]*131+s[i];
		for(int i=0,sz=t.size();i<sz;i++)rt[i+1]=rt[i]*131+t[i];
		int pl=0;
		while(pl<min(s.size(),t.size())&&s[pl]==t[pl])pl++;
		int pr=s.size()-1,rr=t.size()-1;
		while((~pr)&&(~rr)&&s[pr]==t[rr])pr--;
		pr++;
		int c=(int)t.size()-s.size();
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(ad[i]!=c)continue;
			for(int p=0;p<=pl&&p+a[i].size()<=s.size();p++)
				if(p+a[i].size()>=pr)
					if(hashing(p+1,p+a[i].size(),rs)==hs[i]&&hashing(p+1,p+b[i].size(),rt)==ht[i])
						cnt++;
		}
		cout<<cnt<<'\n';
	}
	return 0;
}

