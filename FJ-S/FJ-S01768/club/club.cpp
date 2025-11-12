#include<bits/stdc++.h>
using namespace std;
int n,m,t,c[5];
struct egg{
	int a1,a2,a3;
}a[300000];
int eggsb(egg x,egg y){
	return x.a1>y.a1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
	
		memset(c,0,sizeof(c));
		
		for(int i=1;i<=n;i++) cin>>a[i].a1>>a[i].a2>>a[i].a3;
		
		sort(a+1,a+1+n,eggsb);
	//	cout<<1;
		long long ans=0;
		for(int i=1;i<=n;i++){
		if(c[1]==n/2) {ans+=a[i].a2;c[2]++;}
		else if(c[2]==n/2) {ans+=a[i].a1;c[1]++;}
		     else if(a[i].a1>a[i].a2) {ans+=a[i].a1;c[1]++;}
		         else if(a[i].a1<a[i].a2) {ans+=a[i].a2;c[2]++;}
		          else if(c[1]>c[2]) {ans+=a[i].a2;c[2]++;}
		           else {ans+=a[i].a1;c[1]++;}
		}
		cout<<ans<<endl;
		
	} 
	return 0;
}
