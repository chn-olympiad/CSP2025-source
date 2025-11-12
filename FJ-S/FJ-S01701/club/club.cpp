#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int t,n,ans;
int a[N],b[N],c[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(int k=1;k<=t;k++){
		cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		if(i>0)  ans+=a[i];
	}
	cout<<ans<<endl;
	}
	
	return 0;
}


