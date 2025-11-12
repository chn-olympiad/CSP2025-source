#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500+5;
const int mod=998244353;
int n,m;
char c[N];
int a[N];
ll t1;
ll ans;
bool b[N];
bool h[N];
int s[N];
bool check(){
	int sum=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(sum>=s[i]){
			sum++;
			continue;
		}
		if(c[i]=='0')sum++;
		else cnt++;
	}
	return (cnt>=m);
}
void dfs(int s1,int t){
	if(s1==t+1){
		if(!check())return;
		ans++;
		return;
	}
	
	for(int j=1;j<=n;j++){
		if(h[j])continue;
		s[s1]=a[j];
		h[j]=1;
		dfs(s1+1,t);
		s[s1]=0;
		h[j]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]=='1'&&f)t1++;
		else f=0;
	}
	bool ff=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1)ff=0;
	}
	if(ff||f){
		if(t1>=m){
			ans=1;
			for(int i=n;i>=1;i--){
				ll u=i;
				ans=(ans*u)%mod;
			}
		}
	}
	else{
		dfs(1,n);
	}
	cout<<ans;
	return 0;
} 
