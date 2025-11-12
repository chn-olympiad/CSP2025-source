#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t;
int n;
int a2, b2, c2;
struct qw{
	int a1, b1, c1;
	int best;
	int f, th;
}a[N];
int b1[N], B2[N], b3[N];
int ans;
int M;
int e1, e2, e3;
int cnt;
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int V=n/2;
		for(int i=1; i<=n; i++){
			cin>>a[i].a1>>a[i].b1>>a[i].c1,
		 a[i].best=max(a[i].best, max(a[i].a1, max(a[i].b1, a[i].c1)));
			if(a[i].best==a[i].a1){
				a[i].best=1;
				if(a[i].b1>a[i].c1) a[i].f=a[i].b1, a[i].th=a[i].c1;
				else a[i].f=a[i].c1, a[i].th=a[i].b1;
				a2++;
				ans+=a[i].a1;
			}
			else if(a[i].best==a[i].b1){
				a[i].best=2;
				if(a[i].a1>a[i].c1) a[i].f=a[i].a1, a[i].th=a[i].c1;
				else a[i].f=a[i].c1, a[i].th=a[i].a1;
				b2++;
				ans+=a[i].b1;
			}
			else {
				a[i].best=3;
				if(a[i].b1>a[i].a1) a[i].f=a[i].b1, a[i].th=a[i].a1;
				else a[i].f=a[i].a1, a[i].th=a[i].b1;
				c2++;
				ans+=a[i].c1;
			}
		}
		if(a2>n/2){
			while(a2<=n/2){
			int e=1;
			for(int i=1; i<=n; i++)
				if(a[i].best==1)
					b1[e]=a[i].a1,
					B2[e]=a[i].b1,
					b3[e++]=a[i].c1;
			for(int i=1; i<=e; i++)
			{
				if(M<B2[i]-b1[i])
					M=B2[i]-b1[i],
					e2=i,
					e3=0;
				if(M<b3[i]-b1[i])
					M=b3[i]-b1[i],
					e3=i,
					e2=0;
			}
			if(e2!=0){
				ans-=b1[e2];
				ans+=B2[e2];
			}
			else{
				ans-=b1[e3];
				ans+=b3[e3];
			} 
			a2--;
			}
		}
		if(b2>n/2){
			while(b2<=n/2){
			int e=1;
			for(int i=1; i<=n; i++)
				if(a[i].best==2)
					b1[e]=a[i].a1,
					B2[e]=a[i].b1,
					b3[e++]=a[i].c1;
			for(int i=1; i<=e; i++)
			{
				if(M<b1[i]-B2[i])
					M=b1[i]-B2[i],
					e1=i,
					e3=0;
				if(M<b3[i]-B2[i])
					M=b3[i]-B2[i],
					e3=i,
					e1=0;
			}
			if(e1!=0){
				ans-=B2[e1];
				ans+=b1[e1];
			}
			else{
				ans-=B2[e3];
				ans+=b3[e3];
			} 
			b2--;
			}
		}
		if(c2>n/2){
			while(c2<=n/2){
			int e=1;
			for(int i=1; i<=n; i++)
				if(a[i].best==3)
					b1[e]=a[i].a1,
					B2[e]=a[i].b1,
					b3[e++]=a[i].c1;
			for(int i=1; i<=e; i++)
			{
				if(M<B2[i]-b3[i])
					M=B2[i]-b3[i],
					e2=i,
					e1=0;
				if(M<b1[i]-b3[i])
					M=b1[i]-b3[i],
					e1=i,
					e2=0;
			}
			if(e1!=0){
				ans-=b3[e1];
				ans+=b1[e1];
			}
			else{
				ans-=b3[e2];
				ans+=B2[e2];
			} 
			c2--;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
