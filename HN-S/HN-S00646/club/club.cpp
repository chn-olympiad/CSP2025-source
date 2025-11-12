#include<bits/stdc++.h>
using namespace std;
int t;
int n,bs;
int a,b,c;
int aa[1005],bb[1005],cc[1005];
int zz=0;
int ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
	cin>>n;
	bs=n/2;
	for(int i=1;i<=n;i++){
		cin>>a>>b>>c;
		aa[i]=a;
		bb[i]=b;
		cc[i]=c;
	}
	sort(aa+1,aa+n+1);
	sort(bb+1,bb+n+1);	
	sort(cc+1,cc+n+1);
	zz=aa[n]+bb[n]+cc[n];
	ans=max(zz+aa[n-1],max(zz+bb[n-1],zz+cc[n-1]));
	cout<<ans<<endl;
}
	return 0;
}
