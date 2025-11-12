#include<bits/stdc++.h>
using namespace std;
long long int n,k,cnt,ans,a[500005],f[500005],b[500005];
struct Q{
	long long int l,r;
}q[1000005];
long long int yihuo(int x,int y){
	long long int jbcnt=1,jbs=0;
	while(x>0||y>0){
		if(x%2!=y%2){
			jbs+=jbcnt;
		}
		jbcnt*=2;
		x/=2;y/=2;
	}
	return jbs;
}
void jiance(){
	for(int i=1;i<=cnt;i++)cout<<q[i].l<<" "<<q[i].r<<"\n";
}
bool cmp(Q a,Q b){
	if(a.r==b.r)return a.l<b.l;
	return a.r<b.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int tA=1,tB=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)tA=0;
	}
	if(tA){
		cout<<n/2;
		return 0;
	}
	for(int i=1;i<=n;i++)
		f[i]=yihuo(a[i],f[i-1]);
	for(int u=1;u<=n;u++){
		for(int h=u;h<=n;h++){
			if(abs(f[u-1]-f[h])==k){
				q[++cnt].l=u;
				q[cnt].r=h;
			}
		}
	}
	sort(q+1,q+cnt+1,cmp);
	int lastq=0;
	for(int i=1;i<=cnt;i++){
		if(q[i].l>lastq){
			ans++;
			lastq=q[i].r;
		}
	}
	cout<<ans;
	return 0;
}