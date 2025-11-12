#include<bits/stdc++.h>
using namespace std;
struct Node{
	int a,b,c,f,s,t,i1,i2,i3;
};
Node a[100005];
int n,vis[5];
bool _(Node x,Node y){
	if(x.f-x.s==y.f-y.s){
		return x.s-x.t>y.s-y.t;
	}
	return x.f-x.s>y.f-y.s;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n; 
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].f=max(a[i].a,max(a[i].b,a[i].c));
			a[i].t=min(a[i].a,min(a[i].b,a[i].c));
			if(a[i].a==a[i].f){
				a[i].i1=1;
				if(a[i].b==a[i].t) a[i].s=a[i].c,a[i].i2=3,a[i].i3=2;
				else a[i].s=a[i].b,a[i].i2=2,a[i].i3=3; 
			}else if(a[i].b==a[i].f){
				a[i].i1=2;
				if(a[i].a==a[i].t) a[i].s=a[i].c,a[i].i2=3,a[i].i3=1;
				else a[i].s=a[i].a,a[i].i2=1,a[i].i3=3; 
			}else if(a[i].c==a[i].f){
				a[i].i1=3;
				if(a[i].a==a[i].t) a[i].s=a[i].b,a[i].i2=2,a[i].i3=1;
				else a[i].s=a[i].a,a[i].i2=1,a[i].i3=2; 
			}
		}
		sort(a+1,a+n+1,_);
		vis[1]=0;
		vis[2]=0;
		vis[3]=0;
		for(int i=1;i<=n;i++){
			if(vis[a[i].i1]<n/2){
				vis[a[i].i1]++;
				ans+=a[i].f;
			}else if(vis[a[i].i2]<n/2){
				vis[a[i].i2]++;
				ans+=a[i].s;
			}else{
				vis[a[i].i3++];
				ans+=a[i].t;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
