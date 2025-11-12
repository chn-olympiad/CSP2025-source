#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
int m1,m2,m3;
struct node{
	int a,b,c;
}r[100005];
bool cmp(node a,node b){
	//if(max(a.a,max(a.b,a.c))!=max(b.a,max(b.b,b.c)))return max(a.a,max(a.b,a.c))>max(b.a,max(b.b,b.c));
	int k=max(a.a,max(a.b,a.c)),k2,k3=min(a.a,min(a.b,a.c));
	if(k==a.a&&k3==a.c)k2=a.b;
	if(k==a.a&&k3==a.b)k2=a.c;
	if(k==a.b&&k3==a.c)k2=a.a;
	int _k=max(b.a,max(b.b,b.c)),_k2,_k3=min(b.a,min(b.b,b.c));
	if(_k==b.a&&_k3==b.c)_k2=b.b;
	if(_k==b.a&&_k3==b.b)_k2=b.c;
	if(_k==b.b&&_k3==b.c)_k2=b.a;
	if(_k-_k2!=k-k2)return (bool)(_k-_k2)<(k-k2);
	return (bool)(_k2-_k3)<(k2-k3);
	
}
signed main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		int f=1,ss=0;
		m1=m2=m3=ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>r[i].a>>r[i].b>>r[i].c;
			if(r[i].b!=0||r[i].c!=0)f=0;
			ss+=r[i].a;
		}
		if(f){
			cout<<ss;
			continue;
		}
		sort(r+1,r+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(max(r[i].a,max(r[i].b,r[i].c))==r[i].a){
				if(m1<n/2){
					m1++,ans+=r[i].a;
				}else if(min(r[i].a,min(r[i].b,r[i].c))==r[i].c){
					m2++,ans+=r[i].b;
				}else{
					m3++,ans+=r[i].c;
				}
			}else if(max(r[i].a,max(r[i].b,r[i].c))==r[i].b){
				if(m2<n/2){
					m2++,ans+=r[i].b;
				}else if(min(r[i].a,min(r[i].b,r[i].c))==r[i].c){
					m1++,ans+=r[i].a;
				}else{
					m3++,ans+=r[i].c;
				}
			}else{
				if(m3<n/2){
					m3++,ans+=r[i].c;
				}else if(min(r[i].a,min(r[i].b,r[i].c))==r[i].a){
					m2++,ans+=r[i].b;
				}else{
					m1++,ans+=r[i].a;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
