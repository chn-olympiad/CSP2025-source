#include <bits/stdc++.h>
using namespace std;

int t;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		bool A=true,B=true;
		int n;
		cin>>n;
		if(n!=100000) A=false;
		int a[n+5],b[n+5],c[n+5];
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0 || c[i]!=0) A=false;
			if(c[i]!=0) B=false;
		}
		if(A){
			sort(a+1,a+n+1);
			int sum=0;
			for(int i=n/2;i>=1;i--){
				sum+=a[i];
			}
			cout<<sum<<"\n";
			continue;
		}
		if(B){
			
			continue;
		}
		if(n==2){
			cout<<max(max(a[1],b[1]),c[1])+max(max(a[2],b[2]),c[2])<<"\n";
			continue;
		}
		if(n==4){
			int o[4]={0};
			for(int i=1;i<=4;i++){
				if(max(max(a[i],b[i]),c[i])==a[i]){
					o[1]+=1;
				}else if(max(max(a[i],b[i]),c[i])==b[i]){
					o[2]+=1;
				}else{
					o[3]+=1;
				}
			}
			if(o[1]<=2 && o[2]<=2 && o[3]<=2){
				sort(a+1,a+5);
				sort(b+1,b+5);
				sort(c+1,c+5);
				cout<<a[2]+a[3]+b[2]+b[3]+c[2]+c[3]<<"\n";
			}
			continue;
		}
	}
	return 0;
}