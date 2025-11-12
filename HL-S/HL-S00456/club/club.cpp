#include<bits/stdc++.h>
using namespace std;
long long n,t,ans,sum;
struct node {
	long long x;
	long long y;
	long long z;
};
bool cmpx(node p,node q) {
	return p.x>q.x;
}
node a[100005];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {	//¶à²âÇå¿Õ £¡£¡£¡ 
		ans=0;
		sum=0;
		n=0;
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>(a[i].x)>>(a[i].y)>>(a[i].z);
		}
		sort(a+1,a+n+1,cmpx);
//		for(int i=1;i<=n;i++) {
//			cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<endl;
//		}
		for(int i=1;i<=n;i++) {
			if((sum+1)>n/2) {
//				cout<<"YN"<<endl;
				break;
			}
			else {
//				cout<<"YYYY"<<endl;
				ans+=a[i].x;
				sum++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
