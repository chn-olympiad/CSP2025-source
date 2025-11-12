//GZ-S00161 贵阳市第一中学 张梁予
#include<bits/stdc++.h>
using namespace std;
int t;

struct c{
	int a1,a2,a3;
}a[100005];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,b[100005]={},ans=0;
		cin>>n;
		int lim=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			b[i]=a[i].a1;
		}
		sort(b+1,b+n+1);
		for(int i=n;i>=lim;i--){
			ans+=b[i];
		}
		cout<<ans;
	}
	return 0;
}
