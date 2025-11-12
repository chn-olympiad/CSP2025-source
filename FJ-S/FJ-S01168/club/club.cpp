#include<bits/stdc++.h>
using namespace std;
struct abc {
	long long x[4],l;
} a[100005];
bool gz(abc u,abc v) {
	if(u.l/100==v.l/100)return u.x[u.l/100]>v.x[v.l/100];
	return u.l/100<v.l/100;
}
long long n,T,ans=0;
int ak[100005];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n;
		for(long long i=1; i<=n; i++) {
			cin>>a[i].x[1]>>a[i].x[2]>>a[i].x[3];
			if(a[i].x[1]>=a[i].x[2]&&a[i].x[2]>=a[i].x[3])a[i].l=123;
			else if(a[i].x[1]>=a[i].x[3]&&a[i].x[3]>=a[i].x[2])a[i].l=132;
			else if(a[i].x[2]>=a[i].x[1]&&a[i].x[1]>=a[i].x[3])a[i].l=213;
			else if(a[i].x[2]>=a[i].x[3]&&a[i].x[3]>=a[i].x[1])a[i].l=231;
			else if(a[i].x[3]>=a[i].x[2]&&a[i].x[2]>=a[i].x[1])a[i].l=321;
			else if(a[i].x[3]>=a[i].x[1]&&a[i].x[1]>=a[i].x[2])a[i].l=312;
		}
		sort(a+1,a+1+n,gz);
		bool flag=0;
		int sum=0;
		for(long long i=1; i<=n; i++) {
			if(a[i].l/100==1) {
				if(i>n/2&&(a[i+1].l/100==2||a[i+1].l/100==3||i==n)){
					flag=1;
					for(long long j=1;j<=i;j++){
						ak[j]=a[j].x[1]-a[j].x[(a[j].l%100)/10];
					}
					sort(ak+1,ak+1+i);
					ans+=a[i].x[1];
					for(long long j=1;j<=i-n/2;j++){
						ans-=ak[j];
					}
				}
				else ans+=a[i].x[1];
			}
			else if(a[i].l/100==2){
				if(a[i-1].l/100==1||i==1)sum=i-1;
				if(flag==1)ans+=a[i].x[2];
				else if(flag==0){
					if(i-sum>(n/2)&&(a[i+1].l/100==3||i==n)){
						flag=1;
						for(long long j=1;j<=i-sum;j++){
							ak[j]=a[j].x[2]-a[j].x[(a[j].l%100)/10];
						}
						sort(ak+1,ak+1+i-sum);
						ans+=a[i].x[2];
						for(long long j=1;j<=i-sum-n/2;j++){
							ans-=ak[j];
						}
					}
					else if(i-sum<=(n-2)||a[i+1].l/100!=3||i!=n) ans+=a[i].x[2];
				}
			}
			else {
				if(a[i-1].l/100==2||a[i-1].l/100==1)sum=i-1;
				if(flag==1)ans+=a[i].x[3];
				else {
					if(i-sum>n/2&&i==n){
						for(long long j=1;j<=i-sum;j++){
							ak[j]=a[j].x[3]-a[j].x[(a[j].l%100)/10];
						}
						sort(ak+1,ak+1+i-sum);
						for(long long j=1;j<=i-sum;j++){
							cout<<ak[j]<<' ';
						}
						ans+=a[i].x[3];
						for(long long j=1;j<=i-sum-n/2;j++){
							ans-=ak[j];
						}
					}
					else ans+=a[i].x[3];
				}
			}
		}
		cout<<ans<<'\n';
		ans=0;
	}
	return 0;
}
