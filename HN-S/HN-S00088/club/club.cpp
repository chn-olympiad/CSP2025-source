#include <bits/stdc++.h>
using namespace std;
int t;
struct yg {
	int a,b,c,where;
};
int cmp1(yg x,yg y) {
	return x.a>y.a;
}
int cmp2(yg x,yg y) {
	return x.b>y.b;
}
int cmp3(yg x,yg y) {
	return x.c>y.c;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		long long ans=0;
		yg arr[100010];
		int a[50005]= {},b[50005]= {},a1=0,b1=0;
		for(int i=0; i<n; i++) {
			cin>>arr[i].a>>arr[i].b>>arr[i].c;
		}
		sort(arr,arr+n,cmp1);
		for(int i=0; i<(n/2); i++) {
			ans+=arr[i].a;
			arr[i].where=1;
			a[i]=arr[i+(n/2)].a;
		}
		sort(arr,arr+n,cmp2);
		for(int i=0; i<(n/2); i++) {
			if(arr[i].where!=0) {
				if(arr[i].a<arr[i].b) {
					ans-=arr[i].a;
					ans+=arr[i].b;
					arr[i].where=2;
					ans+=a[a1];
					a1++;
				}
				continue;
			}
			ans+=arr[i].b;
			arr[i].where=2;
			b[i]=arr[i+(n/2)].b;
		}
		sort(arr,arr+n,cmp3);
		for(int i=0; i<(n/2); i++) {
			if(arr[i].where==1) {
				if(arr[i].a<arr[i].c) {
					ans-=arr[i].a;
					ans+=arr[i].c;
					arr[i].where=3;
					ans+=a[a1];
					a1++;
				}
				continue;
			} else if(arr[i].where==2) {
				if(arr[i].b<arr[i].c) {
					ans-=arr[i].b;
					ans+=arr[i].c;
					arr[i].where=3;
					ans+=b[b1];
					b1++;
				}
				continue;
			}
			ans+=arr[i].c;
			arr[i].where=3;
		}
		for(int i=0; i<n; i++) {
//			cout<<i<<"       "<<arr[i].where<<endl;
		}
		cout<<ans<<'\n';
	}
	return 0;
}

