#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=1e6+5;
int n,k;
int a[N];
int s[N];
int ans=0;
struct node{
	int l,r;
}qj[M];
int cnt=0;
bool cmp(node a,node b){
	if(a.r==b.r){
		return a.l<b.l;
	}
	return a.r<b.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			if((s[i]^s[j])==k){
				cnt++;
				qj[cnt].l=j+1;
				qj[cnt].r=i;
			}
		}
	}
	if(cnt>=1){
		sort(qj+1,qj+cnt+1,cmp);
		int ed=qj[1].r;
		ans++;
		for(int i=2;i<=cnt;i++){
			if(qj[i].l>ed){
				ed=qj[i].r;
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
