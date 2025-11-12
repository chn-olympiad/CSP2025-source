#include<bits/stdc++.h>
using namespace std;
int n,k,a[1145140],ans,m,sum;
struct ff{
	int l,r;
}b[1145141];
bool f[1145141];
bool pd(int x){
	int q=b[x].l,p=b[x].r;
	while(q<=p){
		if(f[q]){
			q--;
			for(;q>=b[x].l;q--) f[q]=0;
			return 0;
		}
		f[q]=1;
		q++;
	}
	return 1;
}
void dfs(int i,int s){
	if(i>m){
		ans=max(ans,s);
		return;
	}
	if(pd(i)){
		dfs(i+1,s+1);
		for(int j=b[i].l;j<=b[i].r;j++) f[j]=0;
	}
	dfs(i+1,s);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],a[i]^=a[i-1];
	for(int len=1;len<=n;len++){
		for(int i=1;i<=n-len+1;i++){
			if((a[i+len-1]^a[i-1])==k){
				b[++m].l=i;
				b[m].r=i+len-1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(b[i].r==b[i].l) sum++,f[b[i].l]=1;
	}
	dfs(1,0);
	cout<<ans+sum;
	return 0;
} 
