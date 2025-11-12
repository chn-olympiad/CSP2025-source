#include <bits/stdc++.h>
using namespace std;
struct po{
	int id,gx,zz,sl;
}a[100010];
int n,t,v[100010],l[5];
int cmp(po x,po y){
	return x.gx>y.gx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			int l=(i-1)*3;
			cin>>a[l+1].zz>>a[l+2].zz>>a[l+3].zz;
			int m=min(min(a[l+1].zz,a[l+2].zz),a[l+3].zz);
			a[l+1].gx=a[l+1].zz-m;
			a[l+2].gx=a[l+2].zz-m;
			a[l+3].gx=a[l+3].zz-m;
			a[l+1].id=i;
			a[l+2].id=i;
			a[l+3].id=i;
			a[l+1].sl=1;
			a[l+2].sl=2;
			a[l+3].sl=3;
		}
		sort(a+1,a+3*n,cmp);
		int cnt=0,ans=0,ll=1;
		while(cnt<n){
			if(v[a[ll].id]==0&&l[a[ll].sl]<n/2){
				ans+=a[ll].zz;
				cnt++;	
				v[a[ll].id]=1;
				l[a[ll].sl]++;		
			}
			ll++;
		}
		cout<<ans<<endl;
	}
	return 0;

} 
