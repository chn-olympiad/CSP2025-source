#include<bits/stdc++.h>
using namespace std;
struct man{
	int id;
	int x1,x2,x3;
};
bool cmp(man x,man y){
	int a,a1,a2,a3,b,b1,b2,b3;
	a1=abs(x.x1-x.x2);
	a2=abs(x.x2-x.x3);
	a3=abs(x.x1-x.x3);
	a=a1+a2+a3;
	b1=abs(y.x1-y.x2);
	b2=abs(y.x2-y.x3);
	b3=abs(y.x1-y.x3);
	b=b1+b2+b3;
	return a>b;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int x=n/2;
		man a[n+5];
		for(int i=1;i<=n;i++){
			cin>>a[i].x1>>a[i].x2>>a[i].x3;
			a[i].id=i;
		}
		int ans=0;
		if(n==2){
			ans=max(
			a[1].x1+a[2].x2,
			max(
			a[1].x1+a[2].x3,
			max(
			a[1].x2+a[2].x1,
			max(
			a[1].x2+a[2].x3,
			max(
			a[1].x3+a[2].x1,
			a[1].x3+a[2].x2
			)
			)
			)
			)
			);
			cout<<ans<<endl;
			continue;
		}
		sort(a+1,a+1+n,cmp);
		int s1=0,s2=0,s3=0;
		for(int i=1;i<=n;i++){
			bool x1=0,x2=0,x3=0;
			if(a[i].x1>=a[i].x2&&a[i].x1>=a[i].x3&&s1<x){
				s1++;
				ans+=a[i].x1;
				x1=1;
			}
			if(!x1){
				if(a[i].x2>=a[i].x3&&s2<x){	
					s2++;
					ans+=a[i].x2;
					x2=1;
				}
				else if(s3<x){
					s3++;
					ans+=a[i].x3;
				}
			}
		}
		cout<<ans<<endl;
	}
}
