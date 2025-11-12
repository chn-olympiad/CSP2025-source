#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,cnt,a[N],vis[1048580];
struct node{
	int l,r;
}b[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	vis[0]=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]^=a[i-1];
		if(vis[a[i]^k]){
		  	b[++cnt].l=vis[a[i]^k];
		  	b[cnt].r=i;
		}
		vis[a[i]^k]=i+1;
	}
	int rr=b[1].r,sum=0;
	for(int i=2;i<=cnt;i++){
		if(rr>=b[i].l){sum++;}
		else{rr=b[i].r;}
	}
	cout<<cnt-sum;
	return 0;
}
