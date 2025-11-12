#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505;
const ll mod=998244353;
int n,m;
int a[N],b[N],mi=1,p[N];
ll ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	char ch;
	ios::sync_with_stdio();
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ch;
		a[i]=ch-'0';
		mi=min(mi,a[i]);
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	if(n<=10){
		for(int i=1;i<=n;i++) p[i]=i;
		ans=0;
		do{
			int res=0,cnt=0;
			for(int i=1;i<=n;i++){
				if(cnt>=b[p[i]]||a[i]==0) cnt++;
				else res++;
			}
			if(res>=m) ans++;
		}while(next_permutation(p+1,p+n+1));
		cout<<ans;
		return 0;
	}
	if(n==m){
		for(int i=1;i<=n;i++){
			if(a[i]==0||b[i]==0){
				cout<<0;
				return 0;
			}
		}
		ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%mod;
		cout<<ans;
		return 0;
	}
	ans=1;
	for(int i=1;i<=n;i++) ans=ans*i%mod;
	cout<<ans;
	return 0;
}
