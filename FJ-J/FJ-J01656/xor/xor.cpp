#include<bits/stdc++.h>
using namespace std;
int a[500005],n,k,qz[500005];
bool vis1[500005]={0},vis2[500505]={0};
int ans=0;

struct qj{
	int l,r;
};
vector<qj> qjs;

void dfs(int sum){
	ans=max(ans,sum);
	for(int i=0;i<qjs.size();i++){
		if(!vis2[i]){
			bool ok=1;
			for(int j=qjs[i].l;j<=qjs[i].r;j++){
				if(vis1[j]==1){
					ok=0;
					break;
				}
			}
			if(ok){
				for(int j=qjs[i].l;j<=qjs[i].r;j++) vis1[j]=1;
				vis2[i]=1;
				dfs(sum+1);
				for(int j=qjs[i].l;j<=qjs[i].r;j++) vis1[j]=0;
				vis2[i]=0;
			}
		}
	}
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	bool type1=1;
	qz[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		qz[i]=qz[i-1]^a[i];
		if(type1&&a[i]!=1) type1=0;
	}
	if(type1){
		if(k==0) cout<<n/2;
		else cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int ck=qz[j]^qz[i-1];
			if(ck==k){
				qj hjm;
				hjm.l=i;
				hjm.r=j;
				qjs.push_back(hjm);
			}
		}
	}
	dfs(0);
	cout<<ans;
	
	return 0;
}
