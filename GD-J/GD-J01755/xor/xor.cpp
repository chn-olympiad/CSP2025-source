#include<bits/stdc++.h>
using namespace std;
long long n,k,ans=0;
long long a[500005];
int solve(int l,int r){
	if(l==r)return 0;
	int mid=(l+r)/2;
	solve(l,mid);
	solve(mid+1,r);
	int i,j,flag=0;
	for(i=mid;i>=l;--i){
		if(a[i]==-1){
			flag=1;
			break;
		}
	}
	for(j=mid+1;j<=r;++j){
		if(a[j]==-1){
			flag=1;
			break;
		}
	}
	if(flag)solve(i,j);
	else {
		int re=a[i];a[i]=-1;
		for(int kk=i+1;kk<=j;++kk){
			re=re xor a[kk];
			a[kk]=-1;
		}
		if(re==k)++ans;
		return re==k;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	    if(a[i]==k){
			++ans;
			a[i]=-1;
		}
	}
	int f=1,flag=1;
	while(f<=n){
        while(a[f]==-1)++f;
        flag=f;
		while(a[f]!=-1)++f;
		solve(flag,f-1);
	}
	cout<<ans;
	return 0;
}
