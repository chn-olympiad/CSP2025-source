#include<bits/stdc++.h>
using namespace std;
int o;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>o;
	while(o--){
		int a[100007],b[100007],c[100007],n,anum=0,bnum=0,cnum=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		sort(c+1,c+1+n);
		for(int i=n/2+1;i<=n;i++) anum+=a[i];
		for(int i=n/2+1;i<=n;i++) bnum+=b[i];
		for(int i=n/2+1;i<=n;i++) cnum+=c[i];
		cout<<max(anum,max(bnum,cnum))<<endl;
	}
	return 0;
}
