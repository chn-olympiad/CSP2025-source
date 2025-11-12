#include<bits/stdc++.h>
using namespace std;
long long t,a[500001],b[500001],c[500001],maxa[500001],maxb;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
    for(long long i=1;i<=t;i++){
    	long long n;
    	cin>>n;
    	for(long long j=1;j<=n;j++){
    		cin>>a[j]>>b[j]>>c[j];
    		if(a[j]>b[j]>c[j]||a[j]>c[j]>b[j]){
    			maxa[j]=a[j];
			}
			if(b[j]>a[j]>c[j]||b[j]>c[j]>a[j]){
    			maxa[j]=b[j];
			}
			if(c[j]>a[j]>b[j]||c[j]>b[j]>a[j]){
    			maxa[j]=c[j];
			}
			maxb+=maxa[j];
		}
		cout<<maxb;
	}
	return 0;
}
