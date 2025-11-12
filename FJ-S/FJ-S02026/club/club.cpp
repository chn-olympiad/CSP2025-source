#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[100005];
long long b[100005];
long long c[100005];
long long bb[100005];
long long bbb[100005];
long long aa[100005],l;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	scanf("%lld",&t);
//	cin>>t;
	while(t--){
//		cin>>n;
		scanf("%lld",&n);
		for(long long i=1;i<=n;i++){
			a[i]=0;b[i]=0;c[i]=0;aa[i]=0;bb[i]=0;bbb[i]=0;l=0;
		}
		long long ans=0;
		for(long long i=1;i<=n;i++){
			scanf("%lld %lld %lld",&a[i],&b[i],&c[i]);
//			cin>>a[i]>>b[i]>>c[i];
			if (a[i]>=b[i]&&a[i]>=c[i]){
				bb[i]=1;ans+=a[i];
			}else if (b[i]>=a[i]&&b[i]>=c[i]){
				bb[i]=2;ans+=b[i];
			}else{
				bb[i]=3;ans+=c[i];
			}
			bbb[bb[i]]++;
		}
		if (bbb[1]<=(n/2)&&bbb[2]<=(n/2)&&bbb[3]<=(n/2)){
			cout<<ans<<endl;
//			cout<<"                    true\n";
			continue;
		}
		if (bbb[1]>(n/2)){
			for(long long i=1;i<=n;i++){
				if (bb[i]==1){
					l++;aa[l]=min(a[i]-b[i],a[i]-c[i]);
				}
			}
			sort(aa+1,aa+1+l);
			for(long long i=1;i<=bbb[1]-(n/2);i++){
				ans-=aa[i];
			}
		}else if (bbb[2]>(n/2)){
			for(long long i=1;i<=n;i++){
				if (bb[i]==2){
					l++;aa[l]=min(b[i]-a[i],b[i]-c[i]);
				}
			}
			sort(aa+1,aa+1+l);
			for(long long i=1;i<=bbb[2]-(n/2);i++){
				ans-=aa[i];
			}
		}else{
			for(long long i=1;i<=n;i++){
				if (bb[i]==3){
					l++;aa[l]=min(c[i]-a[i],c[i]-b[i]);
				}
			}
			sort(aa+1,aa+1+l);
			for(long long i=1;i<=bbb[3]-(n/2);i++){
				ans-=aa[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
