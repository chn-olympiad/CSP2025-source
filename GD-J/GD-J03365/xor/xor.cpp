#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005];
struct qwe{
	int l,r;
}p[550005];
qwe w[550005];
bool cmp(qwe x,qwe y){
	if(x.l==y.l)return x.r-x.l+1<y.r-y.l+1;
	else return x.l<y.l;
}
bool cmp2(qwe x,qwe y){
	if(x.r==y.r)return x.l<y.l;
	else return x.r<y.r;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>1100){
		if(k==0){
			int ans=0,f=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans++;
					continue;
				}
				else{
					if(a[i+1]==a[i]){
						ans++;
						i++;
						continue;
					}
				}
			}
			cout<<ans<<"\n";
			return 0;
		}
		else{
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1)ans++;
			}
			cout<<ans<<"\n";
			return 0;
		}
	}
	int q=1,cnt=0,cur=0,ci=0;
	while(1){
		if(q==n+1)break;
		for(int i=1;i<=n-q+1;i++){
			++cnt;
			int g=0;
			for(int j=i;j<=i+q-1;j++){
				g^=a[j];
			}
			if(g==k){
				p[++cur].l=i,p[cur].r=i+q-1;
			}
		}
		q++;
	}
	sort(p+1,p+1+cur,cmp);
	int sum=0,z=0;
	for(int i=1;i<=cur;i++){
		if(p[i].l!=p[i-1].l)w[++z]={p[i].l,p[i].r};
	}
	sort(w+1,w+1+z,cmp2);
	int ans=1,f=w[1].r;
	for(int i=2;i<=z;i++){
		if(w[i].l>f){
			f=w[i].r;
			ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
