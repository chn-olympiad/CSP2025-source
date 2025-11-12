#include<bits/stdc++.h>
using namespace std;
#define N 200010
#define M 5000010
int n,q,tot=1;
string s[N][2],t1,t2,s2[N];
int t[M][27],L[N],R[N];
vector<int>v[M];
void add(int l,int r,int id){
	int i,p=1;
	for(i=l;i<=r;i++){
		int ch=s[id][0][i]-'a'+1;
		if(!t[p][ch])t[p][ch]=++tot;
		p=t[p][ch];
	}
	v[p].push_back(id);
//	mp[p][s[id][1]]++;
}
int ask(string x){
	int i,p=1;
	for(i=0;i<(int)x.size();i++){
		int ch=x[i]-'a'+1;
		p=t[p][ch];
		if(p==0)return 0;
	}
	return p;
}
int findl(string x,string y){
	int i;
	for(i=0;i<(int)x.size();i++)if(x[i]!=y[i])return i;
	return -1;
}
int findr(string x,string y){
	int i;
	for(i=x.size()-1;i>=0;i--)if(x[i]!=y[i])return i;
	return -1;
}
//bool Q(int )
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	int i,j,k,u;
	cin>>n>>q;
//	p[0]=1;
//	for(i=1;i<=M;i++)p[i]=p[i-1]*mod;
	for(i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		int l=findl(s[i][0],s[i][1]);
		int r=findr(s[i][0],s[i][1]);
		L[i]=l,R[i]=r;
//		cout<<l<<" "<<r<<"\n";
		string ss="";
		for(j=l;j<=r;j++)ss+=s[i][1][j];
		s2[i]=ss;
		add(l,r,i);
	}
	for(i=1;i<=q;i++){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<"\n";
			continue;
		}
		int l=findl(t1,t2);
		int r=findr(t1,t2);
		string ss="";
		for(j=l;j<=r;j++)ss+=t1[j];
		int p=ask(ss);
		if(!p){
			cout<<0<<"\n";
			continue;
		}
		string ss2="";
		for(j=l;j<=r;j++)ss2+=t2[j];
//		for(i=1;i<=x.size();i++)hs[i][0]=hs[i-1][0]*mod+t1[i-1],hs[i][1]=hs[i][1]*mod+t2[i-1];
		int ans=0;
		for(j=0;j<(int)v[p].size();j++){
			int x=v[p][j];
			if(l-L[x]<0||(int)s[x][0].size()-1-R[x]+r>=(int)t1.size())continue;
			int op=1;
			for(k=l-L[x],u=0;k<=(int)s[x][0].size()-1-R[x]+r;u++,k++){
				if(t1[k]!=s[x][0][u]||t2[k]!=s[x][1][u]){
					op=0;
					break;
				}
			}
			ans+=op;
		}
		cout<<ans<<"\n";
	}
	return 0;
}/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
/*3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
