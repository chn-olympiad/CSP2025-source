#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[5050],k,ans,sum[5050],vis[5050],li;
struct line{
	int x,y,length;
} l[1000005];
inline bool check(int x,int y){
	for(int i=x;i<=y;i++){
		if(vis[i]==1){
			return 0;
		}
	}
	return 1;
}
inline void print(int x,int y){
	for(int i=x;i<=y;i++){
		vis[i]=1;
	}
}
bool cmp(line a,line b){
	return a.length<b.length;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((sum[j]^sum[i-1])==k){
				li++;
				l[li].x=i;
				l[li].y=j;
				l[li].length=j-i;
			}
		}
	}
	sort(l+1,l+li+1,cmp);
	for(int i=1;i<=li;i++){
		if(check(l[i].x,l[i].y)){
			ans++;
			print(l[i].x,l[i].y);
		}
	}
	cout<<ans;
	return 0;
}