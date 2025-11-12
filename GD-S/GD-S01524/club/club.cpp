#include<bits/stdc++.h>
using namespace std;
int t,n,mx,mx1,mxn,cnt,ans,aa,bb,cc;
struct f{
	int a,b,c,x,mx,mxn;
	int mxid,mxnid;
}a[100005];
bool cmp(f x,f y){
	return x.x>y.x;
}
bool pan;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while (t--){
		cin>>n;
		for (int i=1;i<=n;i++){
			a[i].mx=a[i].mxn=0;
			cin>>a[i].a>>a[i].b>>a[i].c;
			if (a[i].a>a[i].mx){
				a[i].mxn=a[i].mx;
				a[i].mx=a[i].a;
				a[i].mxnid=a[i].mxid;
				a[i].mxid=1;
			}else if (a[i].a>a[i].mxn){
				a[i].mxn=a[i].a;
				a[i].mxnid=1;
			}
			if (a[i].c>a[i].mx){
				a[i].mxn=a[i].mx;
				a[i].mx=a[i].c;
				a[i].mxnid=a[i].mxid;
				a[i].mxid=3;
			}else if (a[i].c>a[i].mxn){
				a[i].mxn=a[i].c;
				a[i].mxnid=3;
			}
			if (a[i].b>a[i].mx){
				a[i].mxn=a[i].mx;
				a[i].mx=a[i].b;
				a[i].mxnid=a[i].mx;
				a[i].mxid=2;
			}else if (a[i].b>a[i].mxn){
				a[i].mxn=a[i].b;
				a[i].mxnid=2;
			}
			a[i].x=a[i].mx-a[i].mxn;
		}
		mx=n/2;
		pan=1;
		cnt=0;
		for (int i=1;i<n;i++){
			if (a[i].x>a[i+1].x) cnt++;
		}
		if (cnt!=n-1) sort(a+1,a+n+1,cmp);
		ans=0;
		aa=bb=cc=0;
		for (int i=1;i<=n;i++){
			if (a[i].mxid==1){
				if (aa>=mx){
					if (a[i].mxnid==2){
						bb++;
						ans+=a[i].mxn;
					}else{
						cc++;
						ans+=a[i].mxn;
					}
				}else{
					aa++;
					ans+=a[i].mx;
				}
			}else if (a[i].mxid==2){
				if (bb>=mx){
					if (a[i].mxnid==1){
						aa++;
						ans+=a[i].mxn;
					}else{
						cc++;
						ans+=a[i].mxn;
					}
				}else{
					bb++;
					ans+=a[i].mx;
				}
			}else if (a[i].mxid==3){
				if (cc>=mx){
					if (a[i].mxnid==1){
						aa++;
						ans+=a[i].mxn;
					}else{
						bb++;
						ans+=a[i].mxn;
					}
				}else{
					cc++;
					ans+=a[i].mx;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
