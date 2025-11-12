#include <bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
	int m1,m2,s1,s2;
}a[100005];
bool cmp(node x,node y){
	return x.m1+y.m2>x.m2+y.m1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){	
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			priority_queue<int> q;
			a[i].m1=max(a[i].a,max(a[i].b,a[i].c));
			if(a[i].m1==a[i].a){
				a[i].m2=max(a[i].b,a[i].c);
				a[i].s1=1;
				if(a[i].c>a[i].b){
					a[i].s2=3;
				}else{
					a[i].s2=2;
				}
			}
			if(a[i].m1==a[i].b){
				a[i].m2=max(a[i].a,a[i].c);
				a[i].s1=2;
				if(a[i].a>a[i].c){
					a[i].s2=1;
				}else{
					a[i].s2=3;
				}
			}if(a[i].m1==a[i].c){
				a[i].m2=max(a[i].b,a[i].a);
				a[i].s1=3;
				if(a[i].a>a[i].b){
					a[i].s2=1;
				}else{
					a[i].s2=2;
				}
			}
		}
		sort(a+1,a+1+n,cmp);
		int sum1=0,sum2=0,sum3=0;
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(a[i].s1==1){
				if(sum1<n/2){
					sum1++;
					ans+=a[i].m1;
				}
				else{
					if(a[i].s2==2){
						if(sum2<n/2){
							sum2++;
							ans+=a[i].m2;
						}else{
							sum3++;
							ans+=a[i].c;
						}
					}
					else{
						if(sum3<n/2){
							sum3++;
							ans+=a[i].m2;
						}else{
							sum2++;
							ans+=a[i].b;
						}
					}
				}
			}
			if(a[i].s1==2){
				if(sum2<n/2){
					sum2++;
					ans+=a[i].m1;
				}
				else{
					if(a[i].s2==1){
						if(sum1<n/2){
							sum1++;
							ans+=a[i].m2;
						}else{
							sum3++;
							ans+=a[i].c;
						}
					}
					else{
						if(sum3<n/2){
							sum3++;
							ans+=a[i].m2;
						}else{
							sum1++;
							ans+=a[i].a;
						}
					}
				}
			}
			if(a[i].s1==3){
				if(sum3<n/2){
					sum3++;
					ans+=a[i].m1;
				}
				else{
					if(a[i].s2==2){
						if(sum2<n/2){
							sum2++;
							ans+=a[i].m2;
						}else{
							sum1++;
							ans+=a[i].a;
						}
					}
					else{
						if(sum1<n/2){
							sum1++;
							ans+=a[i].m2;
						}else{
							sum2++;
							ans+=a[i].b;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
