#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct node{
	int v[4],mx,mx2;
}a[100005];
bool cmp(node x,node y){
	return x.v[x.mx]-x.v[x.mx2]<y.v[y.mx]-y.v[y.mx2];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n,ans=0;
		//cout<<"T:"<<T<<"\n";
		for(int i=0;i<=n+1;++i) a[i].v[0]=a[i].v[1]=a[i].v[2]=0,a[i].mx=a[i].mx2=3;
		for(int i=1;i<=n;++i){
			for(int j=0;j<3;++j){
				cin>>a[i].v[j];
				if(a[i].v[j]>=a[i].v[a[i].mx]) a[i].mx2=a[i].mx,a[i].mx=j;
				else if(a[i].v[j]>a[i].v[a[i].mx2]) a[i].mx2=j;
			}
			a[0].v[a[i].mx]++;
			ans+=a[i].v[a[i].mx];
			//cout<<"I:"<<i<<" "<<a[i].mx<<" "<<a[i].mx2<<" "<<ans<<"\n";
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;++i){
			if(a[0].v[a[i].mx]>n/2){
				ans=ans-a[i].v[a[i].mx]+a[i].v[a[i].mx2];
				a[0].v[a[i].mx]--;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}