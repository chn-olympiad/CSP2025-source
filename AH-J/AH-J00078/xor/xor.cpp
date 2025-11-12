#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef struct Node{
	int x,y;
}Node;
Node m[500005];
int a[500005];
bool cmp(Node a,Node b){
	if(a.x==a.x){
		return a.y<b.y;
	}
	return a.x>b.x;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=1,r=n;
	int ans=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int tmp=0;
			for(int f=i;f<=j;f++){
				tmp=tmp xor a[f];
			}
			if(tmp==k){
				m[++cnt].x=i;
				m[cnt].y=j;
			}
		}
	}
	sort(m+1,m+cnt+1,cmp);
	int x=0,y=0;
	for(int i=1;i<=cnt;i++){
		if(m[i].x>x&&m[i].y>y){
			ans++;
			x=m[i].x;
			y=m[i].y;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
