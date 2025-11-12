//贵阳市第十八中学 陈屹勋 
#include<bits/stdc++.h>
using namespace std;
int n,q,a[10001],b[10001];
bool k,s;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.in","w",stdout);
	cin>>q;
	while(q--){
		cin>>n;
		if(n==2){
			for(int i=1;i<=2;i++){
				cin<<a[i]<<b[i]<<c[i];
			}
			cout<<max(a[1]+b[1],a[1]+b[2],a[1]+c[1],a[1]+c[2],c[1]+b[1],c[2]+b[1],c[1]+b[2],c[2]+b[2]);
			return 0; 
		}
		for(int i = 1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]>0) k=1;
			if(c[i]>0) s=1;
		}
		if(k==0&&s==0){
			sort(a+1,a+n+1);
			for(int i=n;i>=n/2;i--){
				k+=a[i];
			}
			cout<<k;
		}
	}
	return 0;
}
