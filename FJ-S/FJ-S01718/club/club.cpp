#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,f[1000100];
struct id{
	int x[4],mx,id,id2;
}a[1000100],b[1000010];
bool cmp(id a,id b){
	return a.x[a.id]-a.x[a.id2]<b.x[b.id]-b.x[b.id2];
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x[1]>>a[i].x[2]>>a[i].x[3];
		a[i].mx=max(a[i].x[1],max(a[i].x[2],a[i].x[3]));
		if(a[i].mx==a[i].x[1]) a[i].id=1;
		if(a[i].mx==a[i].x[2]) a[i].id=2;
		if(a[i].mx==a[i].x[3]) a[i].id=3;
		if(a[i].id==1){
			if(a[i].x[2]>a[i].x[3]) a[i].id2=2;
			else a[i].id2=3;
		}
		if(a[i].id==2){
			if(a[i].x[1]>a[i].x[3]) a[i].id2=1;
			else a[i].id2=3;
		}
		if(a[i].id==3){
			if(a[i].x[2]>a[i].x[1]) a[i].id2=2;
			else a[i].id2=1;
		}
	}
	int ans=0,p[4]={0};
	for(int i=1;i<=n;i++) ans+=a[i].mx,p[a[i].id]++;
	if(p[1]>n/2){
		int tot=1;
		for(int i=1;i<=n;i++) if(a[i].id==1) b[tot++]=a[i];
		sort(b+1,b+p[1]+1,cmp);
		for(int i=1;i<=p[1]-n/2;i++) ans=ans-b[i].mx+b[i].x[b[i].id2];
		cout<<ans<<endl;
	}else if(p[2]>n/2){
		int tot=1;
		for(int i=1;i<=n;i++) if(a[i].id==2) b[tot++]=a[i];
		sort(b+1,b+p[2]+1,cmp);
		for(int i=1;i<=p[2]-n/2;i++) ans=ans-b[i].mx+b[i].x[b[i].id2];
		cout<<ans<<endl;
	}else if(p[3]>n/2){
		int tot=1;
		for(int i=1;i<=n;i++) if(a[i].id==3) b[tot++]=a[i];
		sort(b+1,b+p[3]+1,cmp);
		for(int i=1;i<=p[3]-n/2;i++) ans=ans-b[i].mx+b[i].x[b[i].id2];
		cout<<ans<<endl;
	}else{
		cout<<ans<<endl;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--) solve(); 
} 
