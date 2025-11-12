#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int w1,w2,w3;
}a[N];
bool cmp1(node a,node b){
	return a.w1>b.w1;
}
bool cmp2(node a,node b){
	return a.w2>b.w2;
}
bool cmp3(node a,node b){
	return a.w3>b.w3;
}
int t,n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i].w1>>a[i].w2>>a[i].w3;
		if(n==2){
			int a1=a[1].w1+a[2].w2,
			a2=a[1].w2+a[2].w1,
			b1=a[1].w1+a[2].w3,
			b2=a[1].w3+a[2].w1,
			c1=a[1].w2+a[2].w3,
			c2=a[1].w3+a[2].w2;
			cout<<max(max(c1,c2),max(max(a1,a2),max(b1,b2)))<<endl;
			continue;
		} 
		if(n==4){
			int a1=a[3].w1+a[4].w2+a[1].w3+a[2].w3,
			a2=a[4].w1+a[3].w2+a[1].w3+a[2].w3,
			a3=a[2].w1+a[4].w2+a[1].w3+a[3].w3,
			a4=a[4].w1+a[2].w2+a[1].w3+a[3].w3,
			a5=a[2].w1+a[3].w2+a[1].w3+a[4].w3,
			a6=a[3].w1+a[2].w2+a[1].w3+a[4].w3,
			a7=a[1].w1+a[4].w2+a[2].w3+a[3].w3,
			a8=a[4].w1+a[1].w2+a[2].w3+a[3].w3,
			a9=a[1].w1+a[3].w2+a[2].w3+a[4].w3,
			a10=a[3].w1+a[1].w2+a[2].w3+a[4].w3,
			a11=a[1].w1+a[2].w2+a[3].w3+a[4].w3,
			a12=a[2].w1+a[1].w2+a[3].w3+a[4].w3,
			b1=a[1].w1+a[2].w1+a[3].w2+a[4].w3,
			b2=a[1].w1+a[2].w1+a[4].w2+a[3].w3,
			b3=a[1].w1+a[3].w1+a[2].w2+a[4].w3,
			b4=a[1].w1+a[3].w1+a[4].w2+a[2].w3,
			b5=a[1].w1+a[4].w1+a[2].w2+a[3].w3,
			b6=a[1].w1+a[4].w1+a[3].w2+a[2].w3,
			b7=a[2].w1+a[3].w1+a[1].w2+a[4].w3,
			b8=a[2].w1+a[3].w1+a[4].w2+a[1].w3,
			b9=a[2].w1+a[4].w1+a[1].w2+a[3].w3,
			b10=a[2].w1+a[4].w1+a[3].w2+a[1].w3,
			b11=a[3].w1+a[4].w1+a[1].w2+a[2].w3,
			b12=a[3].w1+a[4].w1+a[2].w2+a[1].w3,
			c1=a[3].w1+a[1].w2+a[2].w2+a[4].w3,
			c2=a[4].w1+a[1].w2+a[2].w2+a[3].w3,
			c3=a[2].w1+a[1].w2+a[3].w2+a[4].w3,
			c4=a[4].w1+a[1].w2+a[3].w2+a[2].w3,
			c5=a[2].w1+a[1].w2+a[4].w2+a[3].w3,
			c6=a[3].w1+a[4].w2+a[1].w2+a[2].w3,
			c7=a[1].w1+a[2].w2+a[3].w2+a[4].w3,
			c8=a[4].w1+a[2].w2+a[3].w2+a[1].w3,
			c9=a[1].w1+a[4].w2+a[2].w2+a[3].w3,
			c10=a[3].w1+a[4].w2+a[2].w2+a[1].w3,
			c11=a[1].w1+a[3].w2+a[4].w2+a[2].w3,
			c12=a[2].w1+a[3].w2+a[4].w2+a[1].w3,
			d1=a[1].w1+a[2].w1+a[3].w2+a[4].w2,
			d2=a[1].w1+a[3].w1+a[2].w2+a[4].w2,
			d3=a[1].w1+a[4].w1+a[2].w2+a[3].w2,
			d4=a[2].w1+a[1].w1+a[3].w2+a[4].w2,
			d5=a[2].w1+a[3].w1+a[1].w2+a[4].w2,
			d6=a[2].w1+a[4].w1+a[1].w2+a[3].w2,
			d7=a[3].w1+a[1].w1+a[2].w2+a[4].w2,
			d8=a[3].w1+a[2].w1+a[1].w2+a[4].w2,
			d9=a[3].w1+a[4].w1+a[1].w2+a[2].w2,
			d10=a[4].w1+a[1].w1+a[2].w2+a[3].w2,
			d11=a[4].w1+a[2].w1+a[1].w2+a[3].w2,
			d12=a[4].w1+a[3].w1+a[1].w2+a[2].w2,
			e1=a[1].w1+a[2].w1+a[3].w3+a[4].w3,
			e2=a[1].w1+a[3].w1+a[2].w3+a[4].w3,
			e3=a[1].w1+a[4].w1+a[2].w3+a[3].w3,
			e4=a[2].w1+a[1].w1+a[3].w3+a[4].w3,
			e5=a[2].w1+a[3].w1+a[1].w3+a[4].w3,
			e6=a[2].w1+a[4].w1+a[1].w3+a[3].w3,
			e7=a[3].w1+a[1].w1+a[2].w3+a[4].w3,
			e8=a[3].w1+a[2].w1+a[1].w3+a[4].w3,
			e9=a[3].w1+a[4].w1+a[1].w3+a[2].w3,
			e10=a[4].w1+a[1].w1+a[2].w3+a[3].w3,
			e11=a[4].w1+a[2].w1+a[1].w3+a[3].w3,
			e12=a[4].w1+a[3].w1+a[1].w3+a[2].w3,
			f1=a[1].w2+a[2].w2+a[3].w3+a[4].w3,
			f2=a[1].w2+a[3].w2+a[2].w3+a[4].w3,
			f3=a[1].w2+a[4].w2+a[2].w3+a[3].w3,
			f4=a[2].w2+a[1].w2+a[3].w3+a[4].w3,
			f5=a[2].w2+a[3].w2+a[1].w3+a[4].w3,
			f6=a[2].w2+a[4].w2+a[1].w3+a[3].w3,
			f7=a[3].w2+a[1].w2+a[2].w3+a[4].w3,
			f8=a[3].w2+a[2].w2+a[1].w3+a[4].w3,
			f9=a[3].w2+a[4].w2+a[1].w3+a[2].w3,
			f10=a[4].w2+a[1].w2+a[2].w3+a[3].w3,
			f11=a[4].w2+a[2].w2+a[1].w3+a[3].w3,
			f12=a[4].w2+a[3].w2+a[1].w3+a[2].w3;
			int aa=max(max(max(max(max(max(a1,a2),max(a3,a4)),max(a5,a6)),max(a7,a8)),max(a9,a10)),max(a11,a12)),
			bb=max(max(max(max(max(max(b1,b2),max(b3,b4)),max(b5,b6)),max(b7,b8)),max(b9,b10)),max(b11,b12)),
			cc=max(max(max(max(max(max(c1,c2),max(c3,c4)),max(c5,c6)),max(c7,c8)),max(c9,c10)),max(c11,c12)),
			dd=max(max(max(max(max(max(d1,d2),max(d3,d4)),max(d5,d6)),max(d7,d8)),max(d9,d10)),max(d11,d12)),
			ee=max(max(max(max(max(max(e1,e2),max(e3,e4)),max(e5,e6)),max(e7,e8)),max(e9,e10)),max(e11,e12)),
			ff=max(max(max(max(max(max(f1,f2),max(f3,f4)),max(f5,f6)),max(f7,f8)),max(f9,f10)),max(f11,f12));
			cout<<max(max(max(aa,bb),max(cc,dd)),max(ee,ff))<<endl;
			continue;
		} 
		int l;
		for(int i=1;i<=n;i++){
			if(a[i].w1==0&&a[i].w2==0)l+=2;
		}
		if(l==2*n){
			sort(a+1,a+n+1,cmp3);
			for(int i=1;i<=n/2;i++)ans+=a[i].w3;
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			if(a[i].w1==0&&a[i].w3==0)l+=2;
		}
		if(l==2*n){
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n/2;i++)ans+=a[i].w2;
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			if(a[i].w2==0&&a[i].w3==0)l+=2;
		}
		if(l==2*n){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++)ans+=a[i].w1;
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
}
