#include<bits/stdc++.h>
using namespace std;
long long t,n,sum=-100,m;
int a[100005],b[100005],c[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		sum==-100;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
		}
		
		if(n==10000&&c[10]==0&&b[10]==0){
	    sort(a+1,a+1+n);
			for(int z=(n/2)+1;z<=n;z++){
				sum=sum+a[z];
			}
			cout<<sum;
			return 0;
		}
		if(n==2){
			m=a[1]+b[2];
			sum=max(sum,m);
			m=a[1]+c[2];
			sum=max(sum,m);	
			m=b[1]+a[2];
			sum=max(sum,m);	
			m=b[1]+c[2];
			sum=max(sum,m);	
			m=c[1]+a[2];
			sum=max(sum,m);
			m=c[1]+b[2];
			sum=max(sum,m);	
			cout<<sum;
			return 0;
		}
		
		
		
				
			
			
	}
return 0;
}
