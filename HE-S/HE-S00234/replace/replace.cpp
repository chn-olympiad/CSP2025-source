#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=2e5+10,M=5e6+10;
struct nod{
	string a,b;
	int len,i;ull Hash;
}s[N],t[N];
ull Get_Hash(string x){
	ull Hash=0;
	for(int i=0;i<x.size();i++)Hash=Hash*31+x[i]-'a'+1;
	return Hash;
}
ull Pow[M];
bool cmp(nod x,nod y){
	if(x.Hash==y.Hash)return x.len<y.len;
	return x.Hash<y.Hash;	
}
vector<ull>H[N];int ans[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
		s[i].len=s[i].a.size();
		int L=s[i].len+1,R=0;
		for(int j=1;j<=s[i].len;j++){
			if(s[i].a[j-1]!=s[i].b[j-1]){
				R=max(R,j);
				L=min(L,j);
			}
		}
		string s1,s2;
		for(int j=1;j<L;j++)s2+=s[i].a[j-1];
		for(int j=L;j<=R;j++)s1+=s[i].a[j-1];
		for(int j=L;j<=R;j++)s1+=s[i].b[j-1];
		for(int j=R+1;j<=s[i].len;j++)s2+=s[i].a[j-1];
		s[i].a=s1;s[i].b=s2;s[i].len=L-1;
		s[i].Hash=Get_Hash(s1);
	}
	for(int i=1;i<=m;i++){
		cin>>t[i].a>>t[i].b;t[i].i=i;
		t[i].len=t[i].a.size();
		int L=t[i].len+1,R=0;
		for(int j=1;j<=t[i].len;j++){
			if(t[i].a[j-1]!=t[i].b[j-1]){
				R=max(R,j);
				L=min(L,j);
			}
		}
		string s1,s2;
		for(int j=1;j<L;j++)s2+=t[i].a[j-1];
		for(int j=L;j<=R;j++)s1+=t[i].a[j-1];
		for(int j=L;j<=R;j++)s1+=t[i].b[j-1];
		for(int j=R+1;j<=t[i].len;j++)s2+=t[i].a[j-1];
		t[i].a=s1;t[i].b=s2;t[i].len=L-1;
		t[i].Hash=Get_Hash(s1); 
	}
	sort(s+1,s+1+n,cmp);
	sort(t+1,t+1+m,cmp);
	Pow[0]=1;for(int i=1;i<=5e6;i++)Pow[i]=Pow[i-1]*31; 
	int j=1;
	for(int l=1,r;l<=m;l=r+1){
		r=l;
		while(r<m&&t[r+1].Hash==t[l].Hash)r++;
		for(int i=l;i<=r;i++){
			H[i].push_back(0);
			for(int w=0;w<t[i].b.size();w++)H[i].push_back(H[i].back()*31+t[i].b[w]-'a'+1);
		}
		while(j<=n&&s[j].Hash<t[l].Hash)j++;
		int L=j,R=j-1;
		while(R<n&&s[R+1].Hash==t[l].Hash)R++;
		for(int i=L;i<=R;i++)s[i].Hash=Get_Hash(s[i].b);
		for(int i=l;i<=r;i++){
//			cout<<t[i].b<<" "<<H[i].back()<<"\n";
			for(int w=L;w<=R;w++){
//				cout<<t[i].len<<" "<<s[w].len<<"--\n";
				int I=t[i].len,ll=I-s[w].len,rr=I-s[w].len+s[w].b.size();
				if(ll<0||rr>=H[i].size())continue;
//				cout<<ll<<" "<<rr<<"\n";
				ull Hi=H[i][rr]-H[i][ll]*Pow[s[w].b.size()];
				ans[t[i].i]+=(s[w].Hash==Hi);
			}
		}
		j=R+1;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<"\n";
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
