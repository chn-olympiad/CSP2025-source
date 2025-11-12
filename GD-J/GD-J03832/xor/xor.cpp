#include<bits/stdc++.h>
using namespace std;
void inti(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
}
int n,m,k;
int sum,cnt;
int cnta,cntb;
bool A=true,B=true;
int a[500001];
struct node{
	int l,r;
}q[500001];
void dfs(int i,int j,int sl){
	cnt=max(cnt,sl);
	if(i>m){
		return;
	}
	dfs(i+1,j,sl);
	if(q[j].r<q[i].l){
		dfs(i+1,i,sl+1);
	}
}
signed main(){
	inti();
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]!=1){
			A=false;
		}
		if(a[i]>1){
			B=false;
		}
		if(!a[i]){
			++cnta;
		}
		if(a[i]==1){
			++cntb;
		}
	}
	if(A){
		if(n%2==0)cnt=n/2;
		cout<<cnt;
		return 0;
	}
	if(B){
		if(k==0){
			cnt=cnta;
			for(int i=1;i<n;++i){
				if(a[i]==a[i+1]&&a[i]==1){
					++cnt,++i;
				}
			}
		}else{
			cnt=cntb;
		}
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			sum=a[i];
			for(int k=i+1;k<=j;++k){
				sum=(sum^a[k]);
			}
			if(sum==k){
				q[++m].l=i,q[m].r=j;
				break;
			}
		}
	}
	dfs(1,0,0);
	cout<<cnt;
	return 0;
}
