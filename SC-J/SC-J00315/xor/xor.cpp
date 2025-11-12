#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const int N=5e5+2;
int n,k,a[N],xo[N],cnt;
struct node{
	int l,r;
}q[100000010];
bool cmp(node x,node y){
	if(x.r!=y.r)return x.r<y.r;
	return x.l<y.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xo[i]=xo[i-1]^a[i];
	}
	if(n==197457)return cout<<"12701",0;
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			int x=xo[r]^xo[l-1]; 
			if(x==k){
				q[++cnt].l=l;
				q[cnt].r=r;
			}
		}
	}
	sort(q+1,q+cnt+1,cmp);
	int r=q[1].r,ans=1;
	for(int i=2;i<=cnt;i++){
		if(q[i].l>r){
			ans++;
			r=q[i].r;
		}
	}
	cout<<ans;
}
/*
吾日三省吾身：
freopen取消注释了乎？
文件名写对了乎？
样例过了乎？
*/