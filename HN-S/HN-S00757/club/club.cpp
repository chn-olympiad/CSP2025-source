#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005],b[100005],c[100005],ai,bi=0,ci=0,numm=0,maxx=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
			if(b[j]!=0) bi++;
			if(c[j]!=0) ci++;
		} 
		if(bi==0){
			sort(a+1,a+n+1);
			for(int j=n;j>n/2;j--) numm+=a[j];
			cout<<numm;
		}else if(n==2){
			ai=max(a[1]+c[2],a[2]+b[1]);
			bi=max(c[2]+b[1],c[1]+b[2]);
			cout<<max(max(a[1]+b[2],ai),max(a[2]+c[1],bi));
		}else if(ci==0){
			for(int j=1;j<=n/2;j++){
				numm+=a[j];
				numm+=b[n-j+1];
			}
			for(int j=1;j<=n/2;j++)for(int k=n;k>n/2;k--)numm=max(numm+a[k]-a[j]+b[j]-b[k],numm); 
			cout<<numm;
		}else{
			for(int j=1;j<=n;j++){
				numm+=max(max(a[j],b[j]),c[j]);
			}
			cout<<numm;
		}
		cout<<endl;
	}
	return 0;
}

