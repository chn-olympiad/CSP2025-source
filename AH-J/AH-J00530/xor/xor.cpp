#include<bits/stdc++.h>
using namespace std;
const int N=1e5*5+5;
struct node{
	int l,r;
}c[N];
int n,k,a[N],ans,now,b,cnt,nn;
bool cmp(node x,node y){
	return x.r<y.r;}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0){
		int nl=0,nr=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				nl=i,nr=i;
				ans++;
			}else if(a[i]!=0&&i!=1&&a[i]==a[i-1]&&i-1>nr){
				nl=i-1,nr=i;			
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}else if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1) ans++;
		}
		cout<<ans;
		return 0;
	}else{
		for(int i=1;i<=n;i++){
			b=a[i];
			if(b==k){
				++cnt;
				c[cnt].l=i,c[cnt].r=i;}
			for(int j=i+1;j<=n;j++){
				b^=a[j];
				if(b==k){
					++cnt;
					c[cnt].l=i,c[cnt].r=j;
					}}}
		if(cnt==0){
			cout<<"0";
			return 0;}
		sort(c+1,c+cnt+1,cmp);
		now=c[1].r,ans=1;
		for(int i=2;i<=cnt;i++){
			if(c[i].l>now){
				now=c[i].r;
				ans++;}
		}
		cout<<ans;
		return 0;
	}
	return 0;}
