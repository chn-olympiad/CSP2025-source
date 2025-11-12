#include<bits/stdc++.h>
using namespace std;
int a[500005];
struct node{
	int l,r;
}b[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			long long tmp=a[l];
			for(int i=l+1;i<=r;i++){
				tmp=tmp xor a[i];
			}
			if(tmp==k){
				b[++cnt]={l,r};
			}
		}
	}
	int ans=0,last=0;
	for(int i=1;i<=cnt;i++){
		if(b[i].l>last){
			ans++;
			last=b[i].r;
		}
	}
	cout<<ans;
	return 0;
}
