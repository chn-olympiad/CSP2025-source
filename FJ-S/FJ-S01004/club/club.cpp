#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z,dd,tt,jj;
}a[100005];
struct type{
	int h,k,pp;
};
type b[1000005];
type c[1000005];
type d[1000005];
int t,n;
bool cmp(type zx,type zy){
	return zx.pp>zy.pp;
}
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].dd=abs(a[i].x-a[i].y);
			a[i].tt=abs(a[i].x-a[i].z);
			a[i].jj=abs(a[i].z-a[i].y);
		}
		int t1=0,t2=0,t3=0,c1=0,c2=0,c3=0;
		for(int i=1;i<=n;i++){
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
				t1++;
				b[t1].h=i;
				b[t1].k=a[i].x;
				c1+=a[i].x;
				b[i].pp=min(a[i].dd,a[i].tt);
			}
			else if(a[i].y>a[i].x&&a[i].y>=a[i].z){
				t2++;
				c[t2].h=i;
				c[t2].k=a[i].y;
				c2+=a[i].y;
				c[i].pp=min(a[i].dd,a[i].jj);
			}
			else{
				t3++;
				d[t3].h=i;
				d[t3].k=a[i].z;
				c3+=a[i].z;
				d[i].pp=min(a[i].jj,a[i].tt);
			}
		}
		int p=t1;
		int q=t2;
		int j=t3;
		sort(b+1,b+p+1,cmp);
		sort(c+1,c+q+1,cmp);
		sort(d+1,d+j+1,cmp);
		int l=n/2;
		if(t1>l){
			int o=t1-l;
			for(int i=1;i<=o;i++){
				if(a[b[i].h].y>a[b[i].h].z){
					t1--;
					t2++;
					c1-=b[i].k;
					c2+=a[b[i].h].y;
				}
				else{
					t1--;
					t3++;
					c1-=b[i].k;
					c3+=a[b[i].h].z;
				}
			}
		}
		else if(t2>l){
			int o=t2-l;
			for(int i=1;i<=o;i++){
				if(a[c[i].h].x>a[c[i].h].z){
					t2--;
					t1++;
					c2-=c[i].k;
					c1+=a[c[i].h].x;
				}
				else{
					t2--;
					t3++;
					c2-=c[i].k;
					c3+=a[c[i].h].z;
				}
			}
		}
		
		else{
			int o=t3-l;
			for(int i=1;i<=o;i++){
				if(a[d[i].h].x>a[d[i].h].y){
					t3--;
					t1++;
					c3-=d[i].k;
					c1+=a[d[i].h].x;
				}
				else{
					t3--;
					t2++;
					c3-=d[i].k;
					c2+=a[d[i].h].y;
				}
			}
		}
		long long ans=c1+c2+c3;
		cout<<ans<<endl;
	}
	return 0;
}
