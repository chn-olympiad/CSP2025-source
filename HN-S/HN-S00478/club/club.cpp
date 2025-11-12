#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int a[100010],b[100010],c[100010],f[100010],g;
		int cna=0,cnb=0,cnc=0,cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			g=max(a[i],max(b[i],c[i]));
			cnt=cnt+g;
			if(g==a[i]){
				cna++;
				f[i]=min(abs(g-b[i]),abs(g-c[i]));
			}
			if(g==b[i]&&g!=a[i]){
				cnb++;
				f[i]=min(g-a[i],g-c[i]);
			}
			if(g==c[i]&&g!=a[i]&&g!=b[i]){
				cnc++;
				f[i]=min(g-a[i],g-b[i]);
			}
		}
		sort(f+1,f+n+1);
		if(cna<=n/2&&cnb<=n/2&&cnc<=n/2){
			cout<<cnt<<"\n";
		}
		else{
			for(int i=1;i<=n;i++){
				if(cna<=n/2&&cnb<=n/2&&cnc<=n/2){
					cout<<cnt<<"\n";
					break;
				}
				if(cna>n/2){
					for(int j=1;j<=n;j++){
						if(f[i]==a[j]-b[j]){
							cnt=cnt-f[i];
							cna--;
							cnb++;
						}
						if(f[i]==a[j]-c[j]){
							cnt=cnt-f[i];
							cna--;
							cnc++;
						}
					} 
				}
				if(cnb>n/2){
					for(int j=1;j<=n;j++){
						if(f[i]==b[j]-c[j]&&cnb>n/2){
							cnt=cnt-f[i];
							cnb--;
							cnc++;
						}
						if(f[i]==b[j]-a[j]&&cnb>n/2){
							cnt=cnt-f[i];
							cnb--;
							cna++;
						}
					}
				}
				if(cnc>n/2){
					for(int j=1;j<=n;j++){
						if(f[i]==c[j]-a[j]&&cnt>n/2){
							cnt=cnt-f[i];
							cnc--;
							cna++;
						}
						if(f[i]==c[j]-b[j]&&cnt>n/2){
							cnt=cnt-f[i];
							cnc--;
							cnb++;
						}
					}
				}
			}
		}
	}
	return 0;
} 

