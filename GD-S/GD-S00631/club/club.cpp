#include<bits/stdc++.h>
using namespace std;
int T,n,t1,t2,s1=1,s2=1;
struct xin{
	int z,xh;
};
xin jc[100100],a[100100];
bool b[100100];
bool cmp1(xin z1,xin z2){
	return z1.z>z2.z;
}
int main(){
//	freopen("club.in","r",stdin);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		long long ans=0;
		for(int i=1;i<=n;i++){
			int ed;
			cin>>jc[i].z>>a[i].z>>ed;
			jc[i].xh=i;
			a[i].xh=i;
		}
		sort(jc+1,jc+1+n,cmp1);
		sort(a+1,a+1+n,cmp1);
		while(t1+t2!=n){
			while(b[jc[s1].xh]&&s1!=n+1){
				s1++;
			}
			while(b[a[s2].xh]&&s2!=n+1){
				s2++;
			}
			if(jc[s1].z>a[s2].z){
				if(t1<n/2){
					ans+=jc[s1].z;
					b[jc[s1].xh]=1;
					s1++;
					t1++;
				}else{
					jc[s1].z=-1;
				}
			}else{
				if(t2<n/2){
					ans+=a[s2].z;
					b[a[s2].xh]=1;
					s2++;
					t2++;
				}else{
					a[s2].z=-1;
				}
			}
		}
		cout<<ans<<endl;
	}
//	freopen("club.out","w",stdout);
}
