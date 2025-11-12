//club 
#include<bits/stdc++.h>
using namespace std;
long long T,n,ans;
struct node{
	long long a1,a2,a3,ap;
}v[100010];
bool cmp(node x1,node x2){
	return x1.ap>=x2.ap;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		//memset
		for(int i=1;i<=n;i++){
			cin>>v[i].a1>>v[i].a2>>v[i].a3;
			v[i].ap=v[i].a1-v[i].a2;
		}
		//1
		/*for(int i=1;i<=n;i++){
			ans=ans+v[i].a1;
		}*/
		//2
		sort(v+1,v+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			ans+=v[i].a1;
		}
		for(int i=n/2+1;i<=n;i++){
			ans+=v[i].a2;
		}
		//
		cout<<ans<<endl;
	}
	return 0;
}
