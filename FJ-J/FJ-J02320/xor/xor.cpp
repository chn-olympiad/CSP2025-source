#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
};
int a[500005];
int sum[500005];
node g[10000005];
bool cmp(node x,node y){
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		if(a[i]==k){
			cnt++;
			g[cnt].l=i;
			g[cnt].r=i;
		}
	}
	for(int l=1;l<=n-1;l++){
		for(int i=1;i<=n-l;i++){
			int j=i+l;
			int s=sum[j]^sum[i-1];
			if(s==k){
				cnt++;
				g[cnt].l=i;
				g[cnt].r=j;
			}
		}
	}
	sort(g+1,g+1+cnt,cmp);
	int last=0,ans=0;
	for(int i=1;i<=cnt;i++){
		if(g[i].l>last){
			ans++;
			last=g[i].r;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
