#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,k;
int a[N];
struct dist{
	int l;
	int r;
}b[N];
int len;
int m=0;
int vis[N];
int dfs(int p,int f){
	vis[p]=1;
	for(int i=1;i<=len;i++){
		if(!vis[i]){
			if(b[p].r<b[i].l||b[p].l>b[i].r){
				f=dfs(i,f+1);
			}
		}
	}
	return f;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int kk=0;kk<n;kk++){
		for(int i=1;i+kk<=n;i++){
			int p=a[i];
			for(int j=i+1;j<=i+kk;j++){
				p^=a[j];
			}
			if(p==k){
				b[++len].l=i;
				b[len].r=i+kk;
			}
		}
	}
	for(int i=1;i<=len;i++){
		m=max(m,dfs(i,1));
	}
	cout<<m;
	return 0;
}

