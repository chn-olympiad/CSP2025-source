#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[1000005],s[1000005],cnt,anss;
struct node{
	int x,y;
};
bool cmp(node a,node b){
	if(a.y!=b.y)return a.y<b.y;
	else return a.x<b.x;
}
node ans[1000005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int l=s[j]^s[i];
			if(l==k){
				ans[++cnt].x=i+1;
				ans[cnt].y=j;
			}
		}
	}
	sort(ans+1,ans+1+cnt,cmp);
	int now=1;
	for(int i=1;i<=cnt;i++){
		if(ans[i].x>=now){
			anss++;
			now=ans[i].y+1;
		}
	}
	cout<<anss;
	return 0;
}
