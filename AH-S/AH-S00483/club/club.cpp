#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long t,n,ans=0,c1[300005],c2[300005],c3[300005],p1=0,p2=0,p3=0,b[N];
bool YoN1=0,YoN2=0,YoN3=0;
struct node{
	int g1,g2,g3,g0,best;
}a[N];
bool cmp(int x,int y){
	if(a[x].g0!=a[y].g0){
		return a[x].g0>a[y].g0;
	}else{
		return a[x].best>a[y].best;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].g1>>a[i].g2>>a[i].g3;
			if(a[i].g1==0||a[i].g2==0||a[i].g3==0){
				a[i].g0++;
			}
			a[i].best=max(a[i].g1,a[i].g2);
			a[i].best=max(a[i].best,a[i].g3);
			if(a[i].best==a[i].g1){
				p1++;
				c1[p1]=i;
			}else if(a[i].best==a[i].g2){
				p2++;
				c2[p2]=i;
			}else{
				p3++;
				c3[p3]=i;
			}
		}
		sort(c1+1,c1+n+1,cmp);
		sort(c2+1,c2+n+1,cmp);
		sort(c3+1,c3+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			ans+=a[c1[i]].g1;
			ans+=a[c2[i]].g2;
			ans+=a[c3[i]].g3;
		}
		if(p1>n/2){
			YoN1=1;
		}else if(p2>n/2){
			YoN2=1;
		}else if(p3>n/2){
			YoN3=1;
		}
		if(YoN1==1){
			for(int i=n/2+1;i<=p1;i++){
				if(a[c1[i]].g2>a[c1[i]].g3&&YoN2==0){
					p2++;
					ans+=a[c1[i]].g2;
				}else if(a[c1[i]].g2<a[c1[i]].g3&&YoN3==0){
					p3++;
					ans+=a[c1[i]].g3;
				}
			}
			if(p2==n/2){
				YoN2=1;
			}else if(p3==n/2){
				YoN3=1;
			}
		}else if(YoN2==1){
			for(int i=n/2+1;i<=p2;i++){
				if(a[c2[i]].g1>a[c2[i]].g3&&YoN1==0){
					p1++;
					ans+=a[c2[i]].g1;
				}else if(a[c2[i]].g1<a[c2[i]].g3&&YoN3==0){
					p3++;
					ans+=a[c2[i]].g3;
				}
			}
			if(p1==n/2){
				YoN1=1;
			}else if(p3==n/2){
				YoN3=1;
			}
		}else if(YoN3==1){
			for(int i=n/2+1;i<=p3;i++){
				if(a[c3[i]].g2>a[c3[i]].g1&&YoN2==0){
					p2++;
					ans+=a[c3[i]].g2;
				}else if(a[c3[i]].g2<a[c3[i]].g1&&YoN1==0){
					p1++;
					ans+=a[c3[i]].g1;
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
		YoN1=0;
		YoN2=0;
		YoN3=0;
		for(int i=1;i<=p1;i++){
			c1[i]=0;
		}
		for(int i=1;i<=p2;i++){
			c2[i]=0;
		}
		for(int i=1;i<=p3;i++){
			c3[i]=0;
		}
		p1=0;
		p2=0;
		p3=0;
	}
	return 0;
}
