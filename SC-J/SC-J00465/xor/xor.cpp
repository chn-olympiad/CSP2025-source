#include<bits/stdc++.h>
using namespace std;
int a[500005];
struct my{
	int f;
	int id;
};
map<int,my> ma;
struct c{
	int l,r;
}b[500005];
bool cmp(c x,c y){
	if(x.r==y.r){
		return x.l<y.l;
	}
	return x.r<y.r;
}
int cnt=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	int qz=0;
	ma[qz].f=1;
	ma[qz].id=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		qz^=a[i];
//		cout<<qz<<' '<<int(k^qz)<<endl;
		if(ma[k^qz].f==1){
			b[++cnt].l=ma[k^qz].id;
			b[cnt].r=i;
		}	
		ma[qz].f=1;
		ma[qz].id=i+1;
	}
	sort(b+1,b+cnt+1,cmp);
	long long fi=0,la=0,ans=0;
	for(int i=1;i<=cnt;i++){
//		cout<<b[i].l<<' '<<b[i].r<<endl;
		if(b[i].l>la){
			ans++;
			la=b[i].r;
		}
	}
	cout<<ans;
	return 0;
}