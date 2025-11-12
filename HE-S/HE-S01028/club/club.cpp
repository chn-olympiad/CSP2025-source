#include<bits/stdc++.h>
using namespace std;
const int N=10011;
int a[N][4],c[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		bool flag1=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			if(a[i][2]!=0||a[i][3]!=0) flag1=1;
		}
		if(flag1==0){
			for(int i=1;i<=n;i++) c[i]=a[i][1];
			sort(c+1,c+1+n);
			long long ans=0;
			for(int i=n/2+1;i<=n;i++){
				ans+=c[i];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
