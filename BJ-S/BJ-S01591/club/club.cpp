#include<bits/stdc++.h>
using namespace std;
long long a,b,c,sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		long long ans=0,x=n/2,y=n/2,z=n/2;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a,&b,&c);
			ans+=max(a,max(b,c));
		}
		cout<<ans<<endl;
	}
	return 0;
}
