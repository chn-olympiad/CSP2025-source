#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,cnt1,cnt2,cnt3,ans,cha[N],p[N];
struct stu{
	int x1,x2,x3;
}a[N];
void q(stu x,int i){
	if(x.x1>=x.x2&&x.x1>=x.x3)ans+=x.x1,cnt1++,p[i]=1;
	else if(x.x2>=x.x1&&x.x2>=x.x3)ans+=x.x2,cnt2++,p[i]=2;
	else ans+=x.x3,cnt3++,p[i]=3;
}
void solve(){
	ans=cnt1=cnt2=cnt3=0;
	memset(p,0,sizeof(p));
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].x1,&a[i].x2,&a[i].x3);
		q(a[i],i);
//		cout<<ans<<endl;
	}
//	cout<<ans<<endl;
	memset(cha,0x7f,sizeof(cha));
	if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
		cout<<ans<<endl;
		return;
	}else if(cnt1>n/2){
		for(int i=1;i<=n;i++){
			if(p[i]==1){
				cha[i]=a[i].x1-max(a[i].x2,a[i].x3);
			}
		}
		sort(cha+1,cha+n+1);
		for(int i=1;i<=cnt1-n/2;i++){
			ans-=cha[i];
		}
	}else if(cnt2>n/2){
		for(int i=1;i<=n;i++){
			if(p[i]==2){
				cha[i]=a[i].x2-max(a[i].x1,a[i].x3);
			}
		}
		sort(cha+1,cha+n+1);
		for(int i=1;i<=cnt2-n/2;i++){
//			cout<<cha[i]<<endl;
			ans-=cha[i];
		}		
	}else{
		for(int i=1;i<=n;i++){
			if(p[i]==3){
				cha[i]=a[i].x3-max(a[i].x1,a[i].x2);
			}
		}
		sort(cha+1,cha+n+1);
		for(int i=1;i<=cnt3-n/2;i++){
			ans-=cha[i];
		}		
	}
	cout<<ans<<endl;	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--) solve();
	return 0;
}
