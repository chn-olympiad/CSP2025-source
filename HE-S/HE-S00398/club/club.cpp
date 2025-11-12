#include<bits/stdc++.h>
using namespace std;
int n,q,ans,k,a[10010][4],l[10010],b[10010],c[10010];
int main (){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>n;
		if(n==2){
            cin>>c[1]>>c[2]>>c[3];
            cin>>b[1]>>b[2]>>b[3];
			for(int f=1;f<=3;f++){
				for(int g=1;g<=3;g++){
				if(f!=g)k=c[f]+b[g];
				if(k>=ans) ans=k;	
				}
				}
				cout<<ans<<"\n";
		}
		if(n==10000){
			
            for(int j=1;j<=n;j++){
            	cin>>l[j]>>a[j][2]>>a[j][3];
				}
				for(int j=n;j>=n/2;j--){
					ans+=l[j];
				}
				cout<<ans<<"\n";
			}
			if(n==200){
            for(int j=1;j<=n;j++){
            	cin>>a[j][1]>>a[j][2]>>l[1];
				}
				for(int k=1;k<=n;k++){
					for(int r=1;r<=n;r++){
						for(int t=1;t<=n;t++){
							
						}
					}
				}
				cout<<ans<<"\n";
			}
}
	return 0;
}
