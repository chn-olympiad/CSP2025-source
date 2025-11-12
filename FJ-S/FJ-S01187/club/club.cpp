#include<bits/stdc++.h>
using namespace std;
struct abc {
	int x,y,z,maxn,maxn2,maxnnum,maxnnum2,cha;
}a[1110000];
int cmp(abc o,abc y){
	return o.cha>y.cha;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	cin>>t;
	while(t--) {
		int abc1=0,abc2=0,abc3=0;
		int n;
		cin>>n;
		for(int i=1; i<=n; i++) {
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			a[i].maxn=max(a[i].x,max(a[i].y,a[i].z));
			if(a[i].maxn==a[i].x) {
				a[i].maxnnum=1;
				if(a[i].y>a[i].z) {
					a[i].maxn2=a[i].y;
					a[i].maxnnum2=2;
				} else {
					a[i].maxn2=a[i].z;
					a[i].maxnnum2=3;
				}
			 }else  if(a[i].maxn==a[i].y) {
				a[i].maxnnum=2;
				if(a[i].x>a[i].z) {
					a[i].maxn2=a[i].x;
					a[i].maxnnum2=1;
				} else {
					a[i].maxn2=a[i].z;
					a[i].maxnnum2=3;
				}
			}
			else {
				a[i].maxnnum=3;
				if(a[i].y>a[i].x) {
					a[i].maxn2=a[i].y;
					a[i].maxnnum2=2;
				} else {
					a[i].maxn2=a[i].x;
					a[i].maxnnum2=1;
				}
			}
			a[i].cha=a[i].maxn-a[i].maxn2;
		}
		sort(a+1,a+n+1,cmp);
		long long ans=0;
		for(int i=1; i<=n; i++) {
			if(a[i].maxnnum==1) {
				if(abc1<n/2) {
					ans+=a[i].maxn;
					abc1++;
				} else {
					ans+=a[i].maxn2;
					if(a[i].maxnnum2==2){
						abc2++;
					}
					else {
						abc3++;
					}
				}
			}
			else if(a[i].maxnnum==2) {
				if(abc2<n/2) {
					ans+=a[i].maxn;
					abc2++;
				} else {
					ans+=a[i].maxn2;
					if(a[i].maxnnum2==1){
						abc1++;
					}
					else {
						abc2++;
					}
				}
			}
			else {
				if(abc3<n/2) {
					ans+=a[i].maxn;
					abc3++;
				} else {
					ans+=a[i].maxn2;
					if(a[i].maxnnum2==2){
						abc2++;
					}
					else {
						abc1++;
					}
				}
			}
		}
		long long  maxn=ans;
		ans=0;
		abc1=0,abc2=0,abc3=0;
		for(int i=n; i>=1; i--) {
			if(a[i].maxnnum==1) {
				if(abc1<n/2) {
					ans+=a[i].maxn;
					abc1++;
				} else {
					ans+=a[i].maxn2;
					if(a[i].maxnnum2==2){
						abc2++;
					}
					else {
						abc3++;
					}
				}
			}
			else if(a[i].maxnnum==2) {
				if(abc2<n/2) {
					ans+=a[i].maxn;
					abc2++;
				} else {
					ans+=a[i].maxn2;
					if(a[i].maxnnum2==1){
						abc1++;
					}
					else {
						abc2++;
					}
				}
			}
			else {
				if(abc3<n/2) {
					ans+=a[i].maxn;
					abc3++;
				} else {
					ans+=a[i].maxn2;
					if(a[i].maxnnum2==2){
						abc2++;
					}
					else {
						abc1++;
					}
				}
			}
		}
		long long maxn2=ans;
		ans=0;
		abc1=0,abc2=0,abc3=0;
		for(int i=n,j=1; i>=j; i--,j++) {
			if(a[i].maxnnum==1) {
				if(abc1<n/2) {
					ans+=a[i].maxn;
					abc1++;
				} else {
					ans+=a[i].maxn2;
					if(a[i].maxnnum2==2){
						abc2++;
					}
					else {
						abc3++;
					}
				}
			}
			else if(a[i].maxnnum==2) {
				if(abc2<n/2) {
					ans+=a[i].maxn;
					abc2++;
				} else {
					ans+=a[i].maxn2;
					if(a[i].maxnnum2==1){
						abc1++;
					}
					else {
						abc2++;
					}
				}
			}
			else {
				if(abc3<n/2) {
					ans+=a[i].maxn;
					abc3++;
				} else {
					ans+=a[i].maxn2;
					if(a[i].maxnnum2==2){
						abc2++;
					}
					else {
						abc1++;
					}
				}
			}
			if(a[j].maxnnum==1) {
				if(abc1<n/2) {
					ans+=a[j].maxn;
					abc1++;
				} else {
					ans+=a[j].maxn2;
					if(a[j].maxnnum2==2){
						abc2++;
					}
					else {
						abc3++;
					}
				}
			}
			else if(a[j].maxnnum==2) {
				if(abc2<n/2) {
					ans+=a[j].maxn;
					abc2++;
				} else {
					ans+=a[j].maxn2;
					if(a[j].maxnnum2==1){
						abc1++;
					}
					else {
						abc2++;
					}
				}
			}
			else {
				if(abc3<n/2) {
					ans+=a[j].maxn;
					abc3++;
				} else {
					ans+=a[j].maxn2;
					if(a[j].maxnnum2==2){
						abc2++;
					}
					else {
						abc1++;
					}
				}
			}
		}
		cout<<max(ans,max(maxn,maxn))<<endl;
	}
	return 0;
}
