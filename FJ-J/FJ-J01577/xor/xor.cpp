#include<bits/stdc++.h>
using namespace std;
int n,a[900005],w[900005],k,ans,maxn,f;

struct gg{
	int l,r,z;
}t[900005];

bool cmp(gg x,gg y){
	if(x.l!=y.l){
		return x.l<y.l;
	}
	return x.r<y.r;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		w[i]=w[i-1]^a[i];
		if(a[i]==k){
			ans++;
			t[ans].l=i;
			t[ans].r=i;
			t[ans].z=1;
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			f=w[j]^w[i-1];
			if(f==k){
				ans++;
				t[ans].l=i;
				t[ans].r=j;
				t[ans].z=1;
			}
		}
	}
	sort(t+1,t+ans+1,cmp);
	for(int i=1;i<ans;i++){
		for(int j=i+1;j<=ans;j++){
			if(t[j].l>t[i].r){
				t[j].z=max(t[j].z,t[i].z+1);
			}
			maxn=max(maxn,t[j].z);
		}
	}
	cout<<maxn;
	return 0;
} 
