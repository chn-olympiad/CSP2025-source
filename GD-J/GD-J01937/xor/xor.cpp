#include<bits/stdc++.h>
#define int long long 
using namespace std;
int a[500005],cnt,ans;
int sum[500005];
struct node{
	int l,r;
}line[500005];
int f[500005],point[500005],flag[500005];
bool cmp(node a,node b){
	return a.l<b.l;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((sum[j]^sum[i-1])==k){
				//cout<<i<<" "<<j<<"\n";
				line[++cnt].l=i;
				line[cnt].r=j;
			}
		}
	}
	sort(line+1,line+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		point[line[i].l]=i,point[line[i].r]=i;
		flag[line[i].r]=1;
	}
	for(int i=1;i<=500000;i++){
		if(point[i]){
			int last=i;
			if(i==line[point[i]].r||flag[i]){
				for(int j=line[point[i]].l;j>=1;j--){
					f[i]=max(f[i],f[j]+1);
				}
			}
			else{
				for(int j=i;j>=1;j--){
					f[i]=max(f[i],f[j]);
				}
			}
			ans=max(ans,f[i]);
		}
	}
	cout<<ans;
	return 0;
}
/*
4 0
2 1 0 3
*/
