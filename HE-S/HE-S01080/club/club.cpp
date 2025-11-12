#include<bits/stdc++.h>
using namespace std;
int t;
int a[500010][5],d[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    for(int k=1;k<=t;k++){
		int ans=0,n;
    	cin>>n;
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=3;j++){
    			cin>>a[i][j];
			}
		}
		int b[4];
		for(int i=1;i<=n;i++){
			int maxx=-1,cnt=2;
			for(int j=1;j<=3;j++){
				b[j]=a[i][j];
				maxx=max(maxx,a[i][j]);
			}
			sort(b+1,b+4);
			if(maxx==a[i][1]){
				if(d[1]==n/2){
				    maxx=b[cnt];
				    cnt--;
				}
				if(d[1]<n/2) d[1]++;
			} 
			if(maxx==a[i][2]){
				if(d[2]==n/2){
				    maxx=b[cnt];
				    cnt--;
				}
				if(d[2]<n/2) d[2]++;
			} 
			if(maxx==a[i][3]){
				if(d[3]==n/2){
				    maxx=b[cnt];
				    cnt--;
				}
				if(d[3]<n/2) d[3]++;
            }
            ans+=maxx;
			} 
			b[1]=b[2]=b[3]=0;
		cout<<ans<<endl;
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=3;j++){
    			a[i][j]=0;
			}
		}
    }
	return 0;
} 
