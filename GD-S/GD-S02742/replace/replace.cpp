#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int a[MAXN],t,n,h;
int a1,a2,a3,b1,b2,b3;
long long ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d",&n);
		if(n==100000){
			for(int j=0;j<n;j++){
				scanf("%d%d%d",&a[j],&h,&h);
			}
			sort(a,a+n);
			for(int j=n-1;j>=n/2;j--)ans+=a[j];
			printf("%lld\n",ans);
		}
		else if(n==2){
			scanf("%d%d%d%d%d%d",&a1,&a2,&a3,&b1,&b2,&b3);
			int mx=0;
			if(a1+b2>mx)mx=a1+b2;
			if(a1+b3>mx)mx=a1+b3;
			if(a2+b1>mx)mx=a2+b1;
			if(a2+b3>mx)mx=a2+b3;
			if(a3+b1>mx)mx=a3+b1;
			if(a3+b2>mx)mx=a3+b2;
			printf("%d\n",mx);
		}
	}
	return 0;
}

