#include<bits/stdc++.h>
#define int long long
using namespace std;
int t[4],mid,n,ans;
struct tt{
	int x,y,z,o,p,q;
}a[100005];
bool cmp(tt x,tt y){
	if(x.x==y.x){
		if(x.y==y.y)return x.z>y.z;
		return x.y>y.y;
	}return x.x>y.x;
}map<int,int>f;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		mid=n/2;
		ans=0;
		for(int i=1;i<=n;i++){
			a[i].o=1;
			a[i].p=2;
			a[i].q=3;
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].z>a[i].y){
				swap(a[i].z,a[i].y);
				swap(a[i].p,a[i].q);
			}
			if(a[i].x<a[i].y){
				swap(a[i].x,a[i].y);
				swap(a[i].o,a[i].p);
			}if(a[i].z>a[i].y){
				swap(a[i].z,a[i].y);
				swap(a[i].p,a[i].q);
			}
		}sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(t[a[i].o]==mid){
				int r=f[a[i].o];
				if(a[r].y+a[i].x>a[r].x+a[i].y){
					t[a[r].p]++;
					ans+=a[r].y+a[i].x-a[r].x;
					f[a[i].o]=i;
				}else{
					t[a[i].p]++;
					ans+=a[i].y;
				}
			}else{
				t[a[i].o]++;
				ans+=a[i].x;
				f[a[i].o]=i;
			}
		}t[1]=t[2]=t[3]=0;
		cout<<ans<<"\n";
	}
}
