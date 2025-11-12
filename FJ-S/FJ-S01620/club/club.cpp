#include<bits/stdc++.h>
using namespace std;
	int n;int a[100005],b[100005],c[100005];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
	int t;
	cin>>t;
	while(t--) {
	
		cin>>n;bool k=0;
		long long cnt=0;
		for(int i=1; i<=n; i++) {
           cin>>a[i]>>b[i]>>c[i];
           cnt+=max(a[i],max(b[i],c[i]));
           if(b[i]!=0||c[i]!=0) k=1;
		}
		
		if(k==0) {
		sort(a+1,a+1+n);
		long long sum=0;
		int i=n;
		int ti=n/2;
		while(ti--){
			sum+=a[i--];
		}
		cout<<sum<<endl;
		}
      else if(n==2){
       	int big;
       	int bigq;
       	int w,wei;
       	   if(a[1]>=b[1]&&a[1]>=c[1]){
       	   	   big=a[1],w=1;
			}
			if(b[1]>=a[1]&&b[1]>=c[1]){
       	   	big=b[1],w=2;
			}
			if(c[1]>=b[1]&&c[1]>=a[1]){
       	   	big=c[1],w=3;
			}
		
		    if(a[2]>=b[2]&&a[2]>=c[2]){
       	   	   bigq=a[2],wei=1;
			}
			if(b[2]>=a[2]&&b[2]>=c[2]){
       	   	bigq=b[2],wei=2;
			}
			if(c[2]>=b[2]&&c[2]>=a[2]){
       	   	bigq=c[2],wei=3;
			}
			
			
			if(w!=wei) cout<<big+bigq<<endl;
			else {
				int A=a[1]+b[1]+c[1]-max(a[1],max(b[1],c[1]))-min(a[1],min(b[1],c[1]));
				int B=a[2]+b[2]+c[2]-max(a[2],max(b[2],c[2]))-min(a[2],min(b[2],c[2]));
				cout<<max(big+B,A+bigq)<<endl;
			}
	   }else{
	   	cout<<cnt<<endl;
	   }
	}

	return 0;
}
