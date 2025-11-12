#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010],b[100010],c[100010],d[100010],e[100010],yyy,ans,aa,bb;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		aa=0;
		bb=0;
		yyy=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>b[i]){
				d[i]=a[i];
				e[i]=1;
			}else{
				d[i]=b[i];
				e[i]=2;
			}
		}
		for(int i=1;i<=n;i++){
			if(d[i]==1&&aa<yyy){
				aa++;
				ans+=e[i];
			}
			else if(d[i]==2&&bb<yyy){
				bb++;
				ans+=e[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

