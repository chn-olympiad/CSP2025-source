#include<bits/stdc++.h>
using namespace std;
int n,check[100005],ans,num[4];
struct node{
	int id;
	int f[4];
	int maxn,minn;
	int mark[4];
};
bool cmp(node x,node y){
	return x.maxn>y.maxn;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		node a[100005];
		num[1]=num[2]=num[3]=0;
		for(int i=1;i<=n;i++){
			check[i]=0;
			a[i].maxn=0;
			a[i].minn=0x3f3f3f;
			for(int j=1;j<=3;j++){
				cin>>a[i].f[j];
				if(a[i].f[j]>=a[i].maxn){
					a[i].maxn=a[i].f[j];
					a[i].mark[1]=j;
				}
				if(a[i].f[j]<=a[i].minn){
					a[i].minn=a[i].f[j];
					a[i].mark[3]=j;
				}
			}
			for(int j=1;j<=3;j++){
				if(a[i].f[j]!=a[i].maxn&&a[i].f[j]!=a[i].minn){
					a[i].mark[2]=j;
					break;
				}
			}
		}
		sort(a+1,a+n+1,cmp);
		ans=0;
		for(int i=1;i<=n;i++){
			if(num[a[i].mark[1]]<(n/2)){
				ans+=a[i].maxn;
				num[a[i].mark[1]]++;
			}
			else{
				if(num[a[i].mark[2]]<(n/2)){
					ans+=a[i].f[a[i].mark[2]];
					num[a[i].mark[2]]++;
				}
				else{
					ans+=a[i].f[a[i].mark[3]];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
