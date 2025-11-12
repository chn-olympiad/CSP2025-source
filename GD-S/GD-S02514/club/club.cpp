#include<bits/stdc++.h>
using namespace std;
const int po=10000010;
struct tt1{
	int t1,p1;
}a[10000010];
struct tt2{
	int t2,p2;
}b[10000010];
struct tt3{
	int t3,p3;
}c[10000010];
struct tt4{
	int t4,p4;
}f[po];
int cmp1(tt1 x,tt1 y){return x.t1>y.t1;}
int cmp2(tt2 x,tt2 y){return x.t2>y.t2;}
int cmp3(tt3 x,tt3 y){return x.t3>y.t3;}
int cmp4(tt4 x,tt4 y){
	return x.p4<y.p4;
}
int f1[po],m,g1[po],aa[po],bb[po],ans;
int t,n,i,j;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n==2){
			cin>>aa[1]>>aa[2]>>aa[3]>>bb[1]>>bb[2]>>bb[3]; 
			for(i=1;i<=3;i++){
				for(j=1;j<=3;j++){
					if(i==j)continue;
					int k=aa[i]+bb[j];
					ans=max(k,ans);
				}
			} 
			return cout<<ans,0;
		}
		for(i=1;i<=n;i++){
			cin>>a[i].t1>>b[i].t2>>c[i].t3;
			a[i].p1=b[i].p2=c[i].p3=i;
		}
		m=0;
		for(i=1;i<=n/2;i++){
			sort(a+1,a+1+n,cmp1);
			f[++m].t4=a[1].t1;
			f[m].p4=a[1].p1;
			a[1].t1=0;
			sort(b+1,b+1+n,cmp2);
			f[++m].t4=b[1].t2;
			f[m].p4=b[1].p2;
			b[1].t2=0;
			sort(c+1,c+1+n,cmp3);
			f[++m].t4=c[1].t3;
			f[m].p4=c[1].p3;
			c[1].t3=0;
			
		}
		sort(f+1,f+1+m,cmp4);
		int	ans=0,maxn;
		for(i=1;i<=m;i++){
			if(f[i+1].p4!=f[i].p4){
				ans+=f[i].t4;
			}else {
				j=i+1;
				maxn=0;
				while(f[j-1].p4==f[j].p4){
					maxn=max(maxn,f[j-1].t4);
					maxn=max(maxn,f[j].t4);
					j++;
				}
				ans+=maxn;
				cout<<j<<' ';
				i=j-1;
			}
		}
		cout<<ans;
		
	}
}
