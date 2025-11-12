#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5; 
int t,maxn;
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++) {
		int n,a1[N],a2[N],a3[N],sum1,sum2,sum3,sum4,sum5,sum6;
		cin>>n;
		for(int j=1;j<=n;j++) {
			cin>>a1[j]>>a2[j]>>a3[j];			
		}
		sum1=a1[1]+a2[2];
	    sum2=a1[1]+a3[2];
	    sum3=a2[1]+a1[2];
	    sum4=a2[1]+a3[2];
	    sum5=a3[1]+a1[2];
	    sum6=a3[1]+a2[2];
	    cout<<max(sum1,max(sum2,max(sum3,max(sum4,max(sum5,sum6)))));
	}   
	return 0;
}
