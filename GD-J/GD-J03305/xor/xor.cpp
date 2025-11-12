#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,b,a[N],ans,t;
struct node{
	int l,r,s;
}f[N];
bool cmp(node x,node y){
	if(x.s!=y.s) return x.s<y.s;
	if(x.l!=y.l) return x.l<y.l;
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>b;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int res=a[i];
		if(res==b){
			f[++t].l=i;
			f[t].r=i;
			f[t].s=1;
		}
		for(int j=i-1,k=i+1;j>=1&&k<=n;j--,k++){
			res^=a[j];
			res^=a[k];
			if(res==b){
				f[++t].l=j;
				f[t].r=k;
				f[t].s=k-j+1;
			}
		}
		res=a[i]^a[i+1];
		if(res==b){
			f[++t].l=i;
			f[t].r=i+1;
			f[t].s=2;
		}
		for(int j=i-1,k=i+2;j>=1&&k<=n;j--,k++){
			res^=a[j];
			res^=a[k];
			if(res==b){
				f[++t].l=j;
				f[t].r=k;
				f[t].s=k-j+1;
			}
		}
	}
	sort(f+1,f+t+1,cmp);
	int time;
	for(int i=1;i<=t;i++){
		if(time<=f[i].l){
			ans++;
			time=f[i].r+1;
		}
	}
	cout<<ans;
	return 0;
} 
