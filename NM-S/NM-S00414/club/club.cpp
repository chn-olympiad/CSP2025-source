#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long n;
	int t,a[100002],b[100002],c[100002],ans;
	cin>>t;
	for(int j=1;j<=t;j++){
        cin>>n;
	    for(int i=1;i<=n;i++){
		    cin>>a[i]>>b[i]>>c[i];
		    }}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	sort(c+1,c+n+1);
	if(n==2){
	   if(a[2]+b[1]<=a[1]+b[2])cout<<a[1]+b[2];
	   if(a[2]+b[1]>=a[1]+b[2])cout<<a[2]+b[1];
	   if(a[2]+c[1]<=a[1]+c[2])cout<<a[1]+c[1];
	   if(a[2]+c[1]>=a[1]+c[2])cout<<a[2]+c[1];
	   if(b[2]+c[1]>=b[1]+c[2])cout<<b[2]+c[1];
	   if(b[2]+c[1]<=c[1]+c[2])cout<<a[2]+c[1];
}
    if(n==4){
    	if(a[4]==0)cout<<b[4]+b[3]+c[4]+c[3];
	}
	return 0;
}
