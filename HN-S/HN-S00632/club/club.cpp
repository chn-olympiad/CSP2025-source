#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
struct newp{
	ll a1;
	ll b1;
	ll c1;
};
int q,n,ans;
newp a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>q;
	while(q--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].b1>>a[i].c1;
			ans+=max(a[i].a1,max(a[i].b1,a[i].c1));
	 }
	 cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
