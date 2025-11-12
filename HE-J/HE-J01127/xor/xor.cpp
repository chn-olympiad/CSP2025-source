#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl '\n'//½»»¥Ìâ×¢ÊÍ
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
inline ll read(){
	ll x=0,t=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')t=-t;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return t*x;
}
int n,k,a[500005],s[500005];
bool fa,fb,fc;
//   10 20 40 30
queue<pair<int,int> >lr;
int len,ans,r;
signed main(){
	file("xor");
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	fa=1,fb=1,fc=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=1)fa=0;
		if(a[i]>1)fb=0;
		if(a[i]>255)fc=0;
	}
	if(fa)cout<<(n>>1);
	else if(fb){
		int s0=0,s1=0;
		for(int i=1;i<=n;i++){
			if(a[i])s1++;
			else s0++;
		}
		if(k==1){
			cout<<s1;
		}else{
			s1=0;
			for(int i=1;i<n;i++){
				if(a[i]&&a[i+1]){
					s1++;
				}
			}
			cout<<s0+s1;
		}
	}else{
		len=ans=r=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int l=s[j]^s[i-1];
				if(l==k){
					lr.push(make_pair(i,j));
//					cerr<<i<<' '<<j<<' '<<(s[j]^s[i-1])<<endl;
				}
			}
		}
		while(!lr.empty()){
			pair<int,int>nw=lr.front();
			lr.pop();
			if(nw.first>r){
				ans++;
				r=nw.second;
			}
		}
		cout<<ans;
	}
	return 0;
}

