#include <bits/stdc++.h>
#define int long long
#define N 100010
using namespace std;
struct node{
	int idx,ans;
};
bool cmp(node x,node y){
	return x.ans>y.ans;
}
int t,n,sum=0,cnt1=1,cnt2=1,cnt3=1;
node a[N],b[N],c[N];
bool vis[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		memset(vis,false,sizeof(vis));
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].ans,&b[i].ans,&c[i].ans);
			a[i].idx=i,b[i].idx=i,c[i].idx=i;
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		int num1=0,num2=0,num3=0;
		while(1){
			if(num1<=n/2&&vis[a[cnt1].idx]==false){
				sum+=a[cnt1].ans;
				vis[a[cnt1].idx]=true;
			}
			else{
				if(num1<=n/2&&vis[a[cnt1].idx]==true){
					for(int i=1;;i++){
						cnt1++;
						if(vis[a[cnt1].idx]==false){
							sum+=a[cnt1].ans;
							break;
						}
					}
				}
			}
			if(num1+num2+num3==n){
				break;
			}
			if(num2<=n/2&&vis[b[cnt2].idx]==false){
				sum+=b[cnt2].ans;
				vis[b[cnt2].idx]=true;
			}
			else{
				if(num2<=n/2&&vis[b[cnt2].idx]==true){
					for(int i=1;;i++){
						cnt2++;
						if(vis[b[cnt2].idx]==false){
							sum+=b[cnt2].ans;
							break;
						}
					}
				}
			}
			if(num1+num2+num3==n){
				break;
			}
			if(num3<=n/2&&vis[c[cnt3].idx]==false){
				sum+=c[cnt3].ans;
				vis[c[cnt3].idx]=true;
			}
			else{
				if(num3<=n/2&&vis[c[cnt3].idx]==true){
					for(int i=1;;i++){
						cnt3++;
						if(vis[c[cnt3].idx]==false){
							sum+=c[cnt3].ans;
							break;
						}
					}
				}
			}
			if(num1+num2+num3==n){
				break;
			}
			printf("%lld",sum);
		}
		
	}
	return 0;
}
