#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
int n,m;
const int N=510;
string s;
int c[N];
int a[N];
const ll p=998244353;
ll res;
ll cal(int n){
	ll ans=1;
	For(i,1,n){
		ans=(ans%p*i%p);
	}
	return ans%p;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;s=' '+s;
	For(i,1,n)cin>>c[i];
	bool flag=1;
	For(i,1,n){
		if(s[i]=='0'){
			flag=0;
			break;
		}
	}
	if(m==n){
		bool f=1;
		For(i,1,n){
			if(s[i]!='1'){
				f=0;break;
			}
		}
		For(i,1,n){
			if(c[i]==0){
				f=0;break;
			}
		}
		if(!f)cout<<0;
		else cout<<cal(n);
		return 0;
	}
	For(i,1,n)a[i]=i;
	do{	
		int ans=0,ar=0;
		For(i,1,n){
			if(ar>=c[a[i]]){
				ar++;
				continue;
			}
			if(s[i]=='0'){
				ar++;
				continue;
			}
			else ans++;
		}
		if(ans>=m){
			res++;
			res%=p;
		}
	}while(next_permutation(a+1,a+n+1));
	cout<<res;
	return 0;
}
//3 2
//101
//1 1 2


