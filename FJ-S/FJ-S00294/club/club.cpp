#include<bits/stdc++.h>
#define N 100005
using namespace std;
int t,n,a[N][3],f0[N],f1[N],f2[N],n0,n1,n2,ans;
bool cmp(int a,int b){return a>b;}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		n0=0;n1=0;n2=0;ans=0;
		for(int i=0;i<n;i++){
			cin>>a[i][0];
			cin>>a[i][1];
			cin>>a[i][2];
//			printf("%d\t%d\t%d",a[i][0],a[i][1],a[i][2]);
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				f0[n0++]=max(a[i][1],a[i][2])-a[i][0];
				ans+=a[i][0];
//				printf("\t%d\t%d",a[i][0],f[i]);
			}
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				f1[n1++]=max(a[i][0],a[i][2])-a[i][1];
				ans+=a[i][1];
//				printf("\t%d\t%d",a[i][1],f[i]);
			}
			else{
				f2[n2++]=max(a[i][0],a[i][1])-a[i][2];
				ans+=a[i][2];
//				printf("\t%d\t%d",a[i][2],f[i]);
			}
//			printf("\n");
		}
		if(n0<=n/2&&n1<=n/2&&n2<=n/2)cout<<ans<<'\n';
		else{
			if(n0>n/2){
				sort(f0,f0+n0,cmp);
				for(int i=0;i<n0-n/2;i++){
					ans+=f0[i];
				}
			}
			else if(n1>n/2){
				sort(f1,f1+n1,cmp);
				for(int i=0;i<n1-n/2;i++){
					ans+=f1[i];
				}
			}
			else{
				sort(f2,f2+n2,cmp);
				for(int i=0;i<n2-n/2;i++){
					ans+=f2[i];
				}
			}
			cout<<ans<<'\n';
		}
//		cout<<ans;
//		if(!(n0<=n/2&&n1<=n/2&&n2<=n/2)){
//			sort(f,f+n,cmp);
//			for(int i=0;i<max(n0,max(n1,n2))-n/2;i++){
//				ans+=f[i];
//				cout<<f[i];
//			}
//			cout<<" ans="<<ans;
//		}
//		printf("\n");
	}
	return 0;
}
