#include<bits/stdc++.h>
using namespace std;
bool f=1;
int n,a[5005],dis[5005],l;
const long long mod=998244353;
long long sum,s,m=-1145141919810;
long long max(long long a,long long b){
	if(a>b)
		return a;
	return b; 
}

void dfs(int x,int k){
	if(k>x){
		if(s>m*2){
			sum++;
			sum%=mod;
			return;
		}
		return;
	}
	for(int i=l;i<=n;i++){
		if(dis[i]!=1){
			s+=a[i];
			dis[i]=1;
			int r=l;
			l=i;
			long long t=m;
			m=max(m,a[i]);
			dfs(x,k+1);
			s-=a[i];
			dis[i]=0;
			m=t;
			l=r;
		}
	}
	return;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=0;
		}
	}
	for(int i=3;i<=n;i++){
		l=1;
		dfs(i,1);
	}
	cout<<sum%mod;
	return 0;
}
