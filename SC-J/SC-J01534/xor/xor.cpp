#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],yh,ans;
int tr[N];
int lowbit(int x){return (x&-x);}
void update(int x,int v){for(;x<=n;x+=lowbit(x))tr[x]=max(tr[x],v);}
int query(int x,int as=0){for(;x;x-=lowbit(x))as=max(as,tr[x]);return as;}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=i;j>yh;j--){
			sum^=a[j];
			if(sum==m){
				int tmp=query(j-1);
				update(i,tmp+1),ans=max(ans,tmp+1),yh=j;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}