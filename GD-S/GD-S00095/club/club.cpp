#include<bits/stdc++.h>
using namespace std;
int T,n,a[100010][5],f[5],c,use[4];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int m=1;m<=T;m++){
		int ans=0;
		memset(use,0,sizeof(use));
		cin>>n;
		c=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			ans+=max(a[i][1],max(a[i][2],a[i][3]));
		}
		cout<<ans<<endl;
	}
	return 0;
}
