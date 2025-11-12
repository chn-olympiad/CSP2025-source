#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10 ;
struct node{
	int s1,s2,s3;
	bool m;
}a[N];
int T,n;
bool cmp1(node x,node y){
	return x.s1<y.s1;
}
bool cmp2(node x,node y){
	return x.s2<y.s2;
}
bool cmp3(node x,node y){
	return x.s3<y.s3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		long long sum1=0,sum2=0,sum3=0,ans=0;
		cin>>n;
		int x=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].s1>>a[i].s2>>a[i].s3;
			sum1+=a[i].s1;
			sum2+=a[i].s2;
			sum3+=a[i].s3;
		}
		if(sum1>=sum2&&sum1>=sum3){
			sort(a+1,a+n+1,cmp1);
			int sum=n;
			for(int i=1;i<=n;i++){
				if(sum>x){
					sum1-=a[i].s1;
					sum--;
				}else{
					a[i].m=1;
				}
			}
			for(int i=1;i<=n;i++){
				if(!a[i].m){
					ans+=max(a[i].s2,a[i].s3);
				}
			}
			cout<<sum1+ans;
		}else if(sum2>=sum1&&sum2>=sum3){
			sort(a+1,a+n+1,cmp2);
			int sum=n;
			for(int i=1;i<=n;i++){
				if(sum>x){
					sum2-=a[i].s2;
					sum--;
				}else{
					a[i].m=1;
				}
			}
			for(int i=1;i<=n;i++){
				if(!a[i].m){
					ans+=max(a[i].s1,a[i].s3);
				}
			}
			cout<<ans+sum2;
		}else if(sum3>=sum1&&sum3>=sum2){
			sort(a+1,a+n+1,cmp3);
			int sum=n;
			for(int i=1;i<=n;i++){
				if(sum>x){
					sum3-=a[i].s3;
					sum--;
				}else{
					a[i].m=1;
				}
			}
			for(int i=1;i<=n;i++){
				if(!a[i].m){
					ans+=max(a[i].s1,a[i].s2);
				}
			}
			cout<<ans+sum3;
		}
		cout<<"\n";
	}
	return 0;
}
