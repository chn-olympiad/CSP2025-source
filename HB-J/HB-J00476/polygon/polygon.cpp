#include <bits/stdc++.h>
using namespace std;
int a[5010];
int b[5010];
//int dfs(int k,int g,int l){int cnt=0;
//	if(b[k]-b[l]<=g||g<0)return 1;
//	for(int i=1;i<k;i++){
//		cnt+=dfs(i,g-(b[k]-b[i]),l+1);
//	}if(cnt==0)cnt++;
//	return cnt;
//}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	b[0]=0;
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	int cnt=0;
	for(int i=3;i<=n;i++){
		int g=2*a[i];if(a[1]+a[2]>=g)continue;
		for(int j=1;j<=i;j++){
			for(int k=j;k<=i;k++){
				if(b[i]-(b[k]-b[j])>g)cnt++;
			}
		}
		cnt++;
		//cnt=cnt+dfs(i,g,0);
	}
	cout<<cnt;
	return 0;
}
