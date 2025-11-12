#include<bits/stdc++.h>
using namespace std;
int a[5555],st[5555],maxs=-1,sum=0,n,c=0;
long long cnt=0;
bool cmp(int x,int y) {
	return x<y;
}
void dfs(int x) {
	if(x>3) {
		if(sum>2*maxs) {
			cnt=(cnt+1)%998244353;
		}
	}
	for(int i=x;i<=n;i++) {
		if(st[i]==0&&a[i]>c) {
			st[i]=1;
			sum=sum+a[i];
			if(maxs>=a[i]) {
				c=a[i];
				dfs(x+1);
				st[i]=0;
				sum=sum-a[i];
			}
			else {
				int b=maxs;
				maxs=a[i];
				c=a[i];
				dfs(x+1);
				st[i]=0;
				sum=sum-a[i];		
				maxs=b;		
			}
		}
		c=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	dfs(1);
	cout<<cnt;
	return 0;
}
