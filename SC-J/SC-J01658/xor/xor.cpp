#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+9,M=5e6+9;
struct node{
	int x,y;
}b[M];
int n,k,cnt,ans;
int a[N],sum[N];
bool px(node xx,node yy){
	if (xx.y!=yy.y) return xx.y<yy.y;
	else return xx.x<yy.x;
}
bool px2(node xx,node yy){
	if (xx.x!=yy.x) return xx.x<yy.x;
	else return xx.y<yy.y;
}
bool check(int mb){
	int i;
	int cs=0;
	node ch={0,0};
	for (int j=1;j<=cnt;j++){
		if (b[j].x>ch.y){
		//	if (mb==3) cout<<b[j].x<<" "<<b[j].y<<"\n";
			cs++;
			i=b[j].y;
			ch=b[j];
		}
	}
	return cs>=mb;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			int x=sum[j]^sum[i-1];
			if (x==k){
				b[++cnt]={i,j};
			}
		}
	}
	sort(b+1,b+1+cnt,px);
	int l=0,r=cnt;
	while(l<=r){
		int mid=(l+r)>>1;
		if (check(mid)){
			l=mid+1;
			ans=max(ans,mid);
		}
		else{
			r=mid-1;
		}
	}
	sort(b+1,b+1+cnt,px2);
	l=0,r=cnt;
	while(l<=r){
		int mid=(l+r)>>1;
		if (check(mid)){
			l=mid+1;
			ans=max(ans,mid);
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
