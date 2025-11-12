#include<bits/stdc++.h>
using namespace std;
int n,m,h,t;
long long an,j;
string s;
int c[555];
int d[555];
int l[555];
bool f[555];
void dfs(int z,int e){
	if((z+e)==n&&z>=m){
		an++;
		an=an%998244353LL;
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i])continue;
		f[i]=true;
		if(c[i]<=l[i]+e)dfs(z,e+1);
		else dfs(z+1,e);
		f[i]=false;
	}
	return;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	sort(c+1,c+n+1);
	for(int i=0;i<n;i++){
		if(s[i]=='0')l[i+1]=1;
		else if(t==0)t=i+1;
	}
	for(int i=1;i<=n;i++){
		l[i]+=l[i-1];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(c[i]>l[t]){
				h=i;
				break;
			}
		}
		if(h==0)an=0LL;
		else{
			an=1LL;
			for(int i=2;i<n;i++){
				an=(an*(i*1LL))%998244353LL;
			}
		}
		cout<<an;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(c[i]>0){
			h=i;
			break;
		}
	}
	if(l[n]==0){
		if(h==1){
			an=1LL;
			for(int i=2;i<=n;i++){
				an=(an*(i*1LL))%998244353LL;
			}
		}
		else{
			an=0LL;
			long long j=1LL;
			for(int i=2;i<=(n-h+1);i++){
				j=j*(i*1LL);
				j=j%998244353LL;
			}
			an+=j;
			an=an%998244353LL;
			j=1LL;
			for(int i=1;i<=h;i++){
				j=j*((n-h-m+i)*1LL);
				j=j%998244353LL;
			}
			an+=j;
			an=an%998244353LL;
		}
		cout<<an;
		return 0;
	}
	if(m==n){
		if(l[n]>0||h>1)an=0LL;
		cout<<an;
		return 0;
	}
	dfs(0,0);
	cout<<an;
	return 0;
}
