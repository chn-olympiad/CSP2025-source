#include<bits/stdc++.h>
using namespace std;
int a[500010];
int v[500010];
int s[500010];
int n,k,m=0;
void bf(int l,int r,int p){
	int o=0;
	for(int i=l;i<=r;i++){
		o=o^a[i];
	}
	if(o==k){
		if(r>=n){
			
			m=max(m,p+1);
			return;
		}
		else bf(r+1,r+1,p+1);
	}else{
		if(r>=n){
			m=max(m,p);
			return ;
		}
		else {
			if(l<r) bf(l+1,r,p);
			bf(l+1,r+1,p);
			bf(l,r+1,p);
		}
	}
}
int main(){	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		v[i]=v[i-1]^a[i];
	}
	bf(1,1,0);
	cout<<m;
}
