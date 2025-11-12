#include<bits/stdc++.h>
using namespace std;
long long t;
bool mysort(int x,int y){
	if(x>y)	return 1;
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		long long n,a[100001],b[100001],c[100001],ans=0;   
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			cin>>b[i];
		}
		for(int i=1;i<=n;i++){
			cin>>c[i];
		}
		sort(a+1,a+1+n,mysort);
		sort(b+1,b+1+n,mysort);
		sort(c+1,c+1+n,mysort);
		for(int i=1;i<=n/2;i++){
			ans+=a[i]+b[i]+c[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
