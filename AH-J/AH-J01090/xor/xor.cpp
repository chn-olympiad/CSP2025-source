#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,k;
int a[200005];
int f[200005];
struct sj{
	int x,y;
}qj[200005];
bool cmp(sj u,sj v){
	if(u.y!=v.y){
		return u.y<v.y;
	}
	return u.x<v.x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=f[i-1]^a[i];
	}
	int l=1,r=1,cnt=0;
	while(l<=n){
		while(r<=n&&(f[r]^f[l-1])!=k){
			r++;
		}
		if((f[r]^f[l-1])==k){
			qj[++cnt]={l,r};
		}
		l++;
		if(k>1){
			r=l;
		}
	}
	sort(qj+1,qj+cnt+1,cmp);
	int ans=0,ed=0;
	for(int i=1;i<=cnt;i++){
		if(qj[i].x>ed){
			ed=qj[i].y;
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
