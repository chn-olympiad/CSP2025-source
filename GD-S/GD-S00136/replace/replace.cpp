#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=2e5+10,M=5e6+10;
int n,q,len[N],pos[N];
char s1[M],s2[M];
namespace T1{
	const int p=131,mod=1e9+7;
	int h1[N],h2[N];
	int pw[M];
	void init(){
		pw[0]=1;
		for(int i=1;i<M;i++)pw[i]=pw[i-1]*1ll*p%mod;
	}
	void work(int id){
		int m=strlen(s1);
		int res1=0,res2=0;
		for(int i=0;i<m;i++)res1=(1ll*res1*p+s1[i])%mod,res2=(1ll*res2*p+(s2[i]-s1[i]+mod))%mod;//,cout<<res1<<endl;
		h1[id]=res1,h2[id]=res2;
//		cout<<"hash "<<id<<" : "<<res1<<" "<<res2<<endl;
	}
	int f1[M],f2[M],m;
	void work1(int mm){
		m=mm;
		for(int i=1;i<=m;i++)f1[i]=(1ll*f1[i-1]*p+s1[i-1])%mod,f2[i]=(1ll*f2[i-1]*p+(s2[i-1]-s1[i-1]+mod))%mod;
	}
	int get1(int l,int r){
		return (f1[r]-1ll*f1[l-1]*pw[r-l+1]%mod+mod)%mod;
	}
	int get2(int l,int r){
		return (f2[r]-1ll*f2[l-1]*pw[r-l+1]%mod+mod)%mod;
	}
	bool check(int i,int l,int r){
		if(l>r||l<0||r>=m)return false;
		l++,r++;
		return h1[i]==get1(l,r)&&h2[i]==get2(l,r);
	}
}
namespace T2{
	const int p=13331,mod=998244353;
	int h1[N],h2[N];
	int pw[M];
	void init(){
		pw[0]=1;
		for(int i=1;i<M;i++)pw[i]=pw[i-1]*1ll*p%mod;
	}
	void work(int id){
		int m=strlen(s1);
		int res1=0,res2=0;
		for(int i=0;i<m;i++)res1=(1ll*res1*p+s1[i])%mod,res2=(1ll*res2*p+(s2[i]-s1[i]+mod))%mod;
		h1[id]=res1,h2[id]=res2;
	}
	int f1[M],f2[M],m;
	void work1(int mm){
		m=mm;
		for(int i=1;i<=m;i++)f1[i]=(1ll*f1[i-1]*p+s1[i-1])%mod,f2[i]=(1ll*f2[i-1]*p+(s2[i-1]-s1[i-1]+mod))%mod;
	}
	int get1(int l,int r){
		return (f1[r]-1ll*f1[l-1]*pw[r-l+1]%mod+mod)%mod;
	}
	int get2(int l,int r){
		return (f2[r]-1ll*f2[l-1]*pw[r-l+1]%mod+mod)%mod;
	}
	bool check(int i,int l,int r){
		if(l>r||l<0||r>=m)return false;
		l++,r++;
		return h1[i]==get1(l,r)&&h2[i]==get2(l,r);
	}
}
int ask(){
	int m=strlen(s1),m1=strlen(s2);
	if(m!=m1)return 0;
	int k=0,r=0;
	for(int i=m-1;i>=0;i--)if(s1[i]!=s2[i])k=i,r=max(r,i);
	T1::work1(m);
	T2::work1(m);
	int ans=0;
	for(int i=1;i<=n;i++){
		int st=k-pos[i];
		if(st+len[i]-1<r)continue;
		ans+=T1::check(i,st,st+len[i]-1)&&T2::check(i,st,st+len[i]-1);
	}
	return ans;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	T1::init();
	T2::init();
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		T1::work(i);
		T2::work(i);
		len[i]=strlen(s1);
		pos[i]=len[i];
		for(int j=len[i]-1;j>=0;j--)if(s1[j]!=s2[j])pos[i]=j;
	}
	while(q--){
		cin>>s1>>s2;
		cout<<ask()<<endl;
	}
}

