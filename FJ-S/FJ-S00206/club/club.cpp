#include<bits/stdc++.h>
using namespace std;
int n,a[100010],ans,b,c;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int ii=1;ii<=t;ii++){
		cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b>>c;
	}
	sort(a+1,a+1+n);
	for(int i=n;i>n/2;i--){
		ans+=a[i];
	}
	cout<<ans<<endl;
	}
	return 0;       
}
