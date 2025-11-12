#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=100010;
int t;
struct node{
	int s1;
	int s2;
	int s3;
};
bool cmp_1(node x,node y){
	return min(abs(x.s1-x.s2),abs(x.s1-x.s3)) < min(abs(y.s1-y.s2),abs(y.s1-y.s3));
}
bool cmp_2(node x,node y){
	return min(abs(x.s1-x.s2),abs(x.s2-x.s3)) < min(abs(y.s1-y.s2),abs(y.s2-y.s3));
}
bool cmp_3(node x,node y){
	return min(abs(x.s3-x.s2),abs(x.s1-x.s3)) < min(abs(y.s3-y.s2),abs(y.s1-y.s3));
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,st1=0,st2=0,st3=0,ans=0;
		cin>>n;
		node a[maxn],c1[maxn],c2[maxn],c3[maxn];
		for(int i=1;i<=n;i++){
			cin>>a[i].s1>>a[i].s2>>a[i].s3;
			if(a[i].s1>=a[i].s2&&a[i].s1>=a[i].s3){
				st1++;
				c1[i].s1=a[i].s1;
				c1[i].s2=a[i].s2;
				c1[i].s3=a[i].s3;
				ans+=a[i].s1;
			}
			else if(a[i].s2>a[i].s1&&a[i].s2>a[i].s3){
				st2++;
				c2[i].s1=a[i].s1;
				c2[i].s2=a[i].s2;
				c2[i].s3=a[i].s3;
				ans+=a[i].s2;
			}
			else{
				st3++;
				c3[i].s1=a[i].s1;
				c3[i].s2=a[i].s2;
				c3[i].s3=a[i].s3;
				ans+=a[i].s3;
			}
		}
//		cout<<ans<<endl;
//		for(int i=1;i<=n;i++){
//			cout<<c1[i].s1<<c1[i].s2<<c1[i].s3<<'\n';
//		}
//		cout<<endl;
//		for(int i=1;i<=n;i++){
//			cout<<c2[i].s1<<c2[i].s2<<c2[i].s3<<'\n';
//		}
//		cout<<endl;
//		for(int i=1;i<=n;i++){
//			cout<<c3[i].s1<<c3[i].s2<<c3[i].s3<<'\n';
//		}
//		cout<<endl;
		while(st1>n/2){
			sort(c1+1,c1+n+1,cmp_1);
//			for(int i=1;i<=n;i++){
//				cout<<c1[i].s1<<c1[i].s2<<c1[i].s3<<'\n';
//			}
			if(c1[1].s2>c1[1].s3){
				ans-=c1[1].s1;
				ans+=c1[1].s2;
			}
			else{
				ans-=c1[1].s1;
				ans+=c1[1].s3;
			}
			st1--;
		}
		while(st2>n/2){
			sort(c2+1,c2+n+1,cmp_2);
//			for(int i=1;i<=n;i++){
//				cout<<c2[i].s1<<c2[i].s2<<c2[i].s3<<'\n';
//			}
			if(c2[1].s1>c2[1].s3){
				ans-=c2[1].s2;
				ans+=c2[1].s1;
			}
			else{
				ans-=c2[1].s2;
				ans+=c2[1].s3;
			}
			st2--;
		}
		while(st3>n/2){
			sort(c3+1,c3+n+1,cmp_3);
//			for(int i=1;i<=n;i++){
//				cout<<c3[i].s1<<c3[i].s2<<c3[i].s3<<'\n';
//			}
			if(c3[1].s1>c3[1].s2){
				ans-=c3[1].s3;
				ans+=c3[1].s1;
			}
			else{
				ans-=c3[1].s3;
				ans+=c3[1].s2;
			}
			st3--;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
