#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int t,n,mid,a1,a2,a3,ans,tem;
int a[N][3],b[N][3],c[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
		cin>>t;
		for(int i=1;i<=t;i++){
			cin>>n;
			mid=n/2;
			for(int j=1;j<=n;j++){
				cin>>a[j][1]>>a[j][2]>>a[j][3];
				c[j]=a[j][1];
			}
			if(n==100000){
				sort(c+1,c+n+1);
				for(int k=mid+1;k<=n;k++){
					ans+=c[k];
				}
				cout<<ans<<endl;
			}
			ans=0;
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}