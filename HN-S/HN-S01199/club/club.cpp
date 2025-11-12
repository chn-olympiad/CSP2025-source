#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5; 
int t,n,a[N],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		cin>>n;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=3;j++)
				cin>>a[3*(i-1)+j];	
		sort(a+1,a+3*n);
		for (int i=n*3;i>=n*3-n/2;i--)
			ans+=a[i];
		cout<<ans<<endl;
	}
	return 0;
}


