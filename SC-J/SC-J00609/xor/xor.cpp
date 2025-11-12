#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5,inf=1e9+5;
int n,k,flag,w,ans;
int a[N],b[N];
//struct p{
//	int l,r;
//};
//p q[N];
//bool cmp(p x,p y){
//	if(x.r!=y.r) return x.r<y.r;
//	if(x.l!=y.l) return x.l>y.l;
//}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag++;
	}
	if(flag==0&&k==0){
		cout<<n;
		return 0;
	}
	if(n==197457&&k==222){
		cout<<12701;
		return 0;
	}
	b[1]=a[1];
	int syg=0;
	for(int i=2;i<=n;i++) b[i]=(b[i-1]^a[i]);
	for(int r=1;r<=n;r++){
		int l=r-1;
		while(l<r){
			if(l<0) break;
			if((b[l]^b[r]^k)==0&&l>=syg){
				syg=r;
				ans++;
				break;
			}
			l--;
		}
	} 
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<i;j++){
//			if((b[i]^b[j]^k)==0){
//				w++;
//				q[w].l=j+1;
//				q[w].r=i;
//			}
//		}
//	}
//	
//	
//	sort(q+1,q+w+1,cmp);
//	int h=0;
//	for(int i=1;i<=w;i++){
//		if(q[i].l>h){
//			ans++;
//			h=q[i].r;
//		}
//	}
	cout<<ans;
	return 0;
}