#include<bits/stdc++.h>
using namespace std;
struct Student {
	int a1,a2,a3;
} a[100005];
bool cmp(Student a,Student b) {
	return a.a1>b.a1;
}
bool cmp2(int a,int b) {
	return a>b;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		int k[n],p[n],q[n];
		int b=0,c=0,sum=0;
		for(int i=1; i<=n; i++) {
			a[i].a1=0;
			a[i].a2=0;
			a[i].a3=0;
		}
		for(int i=1; i<=n; i++) {
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			k[i]=a[i].a1,p[i]=a[i].a2,q[i]=a[i].a3;
			if(a[i].a2!=0)b++;
			if(a[i].a3!=0)c++;
		}
		if(b==0&&c==0) {
			sort(a+1,a+n+1,cmp);
			for(int i=1; i<=n/2; i++) {
				sum+=a[i].a1;
			}
			cout<<sum<<endl;
			continue;
		}
		sort(k+1,k+n+1,cmp2);
		sort(p+1,p+n+1,cmp2);
		sort(q+1,q+n+1,cmp2);
		int ans[100005]= {0};
		int l=0;
		for(int i=1; i<=n/2; i++) {
			ans[l++]=k[i];
			ans[l++]=p[i];
			ans[l++]=q[i];
		}
		sort(ans,ans+l,cmp2);
		for(int i=0; i<n; i++) {
			sum+=ans[i];
		}
		cout<<sum;
	}
	return 0;
}
