#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll q,n,a2[200001],b[200001],c[200001],a3[200001],b1[200001],c1[200001],ans1,ans2,ans3;
void msort(ll l,ll r,ll a[],ll a1[]){
	if(l==r) return;
	ll mid=l+r>>1,r1=mid+1,l2=l;
	msort(l,mid,a,a1);msort(mid+1,r,a,a1);
	ll t1[200001],t2[200001],p=l;
	while(l<=mid&&r1<=r)  {
		if(a[l]<a[r1]) {
			t1[p]=a[r1];
			t2[p]=a1[r1];
			r1++;
		}
		else {
			t1[p]=a[l];
			t2[p]=a1[l];
			l++;
		} 
		p++;		
	}
	while(l<=mid) {
		t1[p]=a[l];
		t2[p]=a1[l];
		l++;
		p++;
	}
	while(r1<=r) {
		t1[p]=a[r1];
		t2[p]=a1[r1];
		p++;
		r1++;
	}
	for(int i=l2;i<=r;i++) {
		a[i]=t1[i];
		a1[i]=t2[i];
	}
}
ll judge(ll a1[],ll a[],ll b[],ll c[],ll g1,ll g2,ll g3){
	ll ans;
	for(int j=1;j<=n;j++) {
			ll p=a1[j];
			if(g2<n/2&&g1==n/2-1&&b[p]+a[a1[j+1]]>a[p]+b[a1[j+1]]&&j<n)  {
				g2++;
				ans+=b[p];
			}
			else if(g3<n/2&&g1==n/2-1&&c[p]+a[a1[j+1]]>a[p]+b[a1[j+1]]&&j<n)  {
				g3++;
				ans+=c[p];
			}
			else if(a[p]>b[p]&&a[p]>c[p]&&g1<n/2) {
				g1++;
				ans+=a[p];
			}
			else if(g1>=n/2) {
				if(b[p]>c[p]) ans+=b[p];
				else ans+=c[p];
			}
			else if(a[p]<b[p]&&a[p]<c[p]) {
				if(b[p]<c[p]&&g3<n/2) {
					g3++;
					ans+=c[p];
				} 
				else {
					g2++;
					ans+=b[p];
				}
			}
			else if(a[p]>b[p]&&a[p]<c[p]){
				if(g3<n/2) {				g3++;
				ans+=c[p];}
				else {
					g1++;
					ans+=a[p];
				}
			} 
			else {
				if(g2<n/2) {
					g2++;
					ans+=b[p];
				}
				else {
					g1++;
					ans+=a[p];
				}
			}
		}
		return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>n;
		ans1=ans2=ans3=0;
		for(int j=1;j<=n;j++){
			cin>>a2[j]>>b[j]>>c[j];a3[j]=b1[j]=c1[j]=j;
		}
		msort(1,n,a2,a3);
		msort(1,n,b,b1);
		msort(1,n,c,c1);
		ans1=judge(a3,a2,b,c,0,0,0);
		ans2=judge(b1,b,a2,c,0,0,0);
		ans3=judge(c1,c,a2,b,0,0,0);
		cout<<max(max(ans1,ans2),ans3)<<endl;
	}
}
