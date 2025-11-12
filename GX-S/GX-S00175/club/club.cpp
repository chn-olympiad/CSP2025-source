#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("club.in","w",stdin);
	freopen("club.out","r",stdout);
	cin>>t;
	while(t--){
		int n,a[100010][5],ans=0,maxd,maxdid;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		maxd=a[1][1];
		maxdid=1;
		for(int k=1;k<=n/2;k++){
			for(int i=1;i<=n;i++){
				if(maxd<a[i][1]){
					maxd=a[i][1];
					maxdid=i;
				}
			}
			ans+=maxd;
			a[maxdid][1]=0;
		}
		cout<<ans<<endl;
	}
	return 0;
}
