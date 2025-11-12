#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
const int N=5005;
int n,m,k,a[N],ans,l,r,num1,x[N],top,lst;
bool flaga=1,flagb=1;
struct node{
	int l,r;
}b[N];
bool cmp(node q,node p){
	return q.r<p.r;
}
void fen(){
	if(flaga&&k==0){
		cout<<n/2;
		exit(0);
	}
	if(flagb&&k<=1){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0)ans++;
				else if(a[i-1]==1)ans++,a[i]=0;
			}
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==1)ans++;
			}
		}
		cout<<ans;
		exit(0);
	}
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flaga=0;
		if(a[i]>1)flagb=0;
	}
	fen();
	for(int i=1;i<=n;i++){
		x[i]=x[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((x[j]^x[i-1])==k){
				b[++top].l=i,b[top].r=j;
			}
		}
	}
	sort(b+1,b+top+1,cmp);
	for(int i=1;i<=top;i++){
		if(b[i].l>b[lst].r)ans++,lst=i;
	}
	cout<<ans;
	return 0;
}