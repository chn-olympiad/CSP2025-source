#include<bits/stdc++.h>
using namespace std;
int t;
int a[100005][3],a1[1000005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		memset(a,0,sizeof(a));
		int f=1;
		int n,p;
		cin>>n;
		int ans=0;
		for(int j=1;j<=n;j++){
			cin>>a[j][0]>>a[j][1]>>a[j][2];
			a1[j]=a[j][0];
			ans+=max(a[j][0],max(a[j][1],a[j][2]));
			if(a[j][1]!=0|| a[j][2]!=0)f=0;
		}
		if(f==1){
			ans=0;
			sort(a1,a1+n+1);
			for(int j=n;j>n/2;j--){
				ans+=a1[j];
			}
			cout<<ans;
			continue;
		}
		cout<<ans<<endl;
	}
	return 0;
}

