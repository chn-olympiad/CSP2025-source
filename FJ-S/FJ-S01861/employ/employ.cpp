#include<bits/stdc++.h>
#define int long long
using namespace std;
long long n,m,l,as,p;
int c[10005];
char s[10005];
bool f[10005];
long long a[10005],ans[10005]; 
void dfs(int x){
	if(x>n){
		int y=0;
		for(int i=1;i<=n;i++){
			if(ans[i]>c[i-1]&&s[i-1]=='1'){
				y++;
				c[i]=c[i-1];
			}else{
				c[i]=c[i-1]+1;
			}
		}	
		if(y>=m){
			as++;
			as%=998244353;
		} 
		return ;
	} 
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			f[i]=1;
			ans[x]=a[i];
			dfs(x+1);
			f[i]=0;
		}	
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		if(a[i]==0){
			p++;
		}
	}
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			l++;
		}
	}
	if(n>10){
		if(l<m){
		cout<<0;
		return 0;
	}
	bool flag=0;
	if(n==m){
		if(p>=1){
			cout<<0;
			return 0; 
		}
		long long x=1;
		for(int i=1;i<=n;i++){
			x*=i;
			x%=998244353;
		}
		cout<<x;
		return 0;
	}
	if(l==n){
		long long x=1,d=0;
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			if(a[i]==0||a[i]<=d){
				d++;
			}
		}
		n-=d;
//		if(d==1)
		for(int i=1;i<=n;i++){
			x*=i;
			x%=998244353;
		}
		cout<<x;
		return 0;
	}
	if(m==1){
		int d=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0||a[i]<=d){
				d++;
			}
		}
		n-=d;
		cout<<n;
		return 0;
		}
	}
	
	dfs(1);
	cout<<as;
	return 0;
} 
