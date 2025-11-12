#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
int a[N][4];
int ans=0;
int b[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
    	scanf("%d",&n);
    	b[1]=b[2]=b[3]=0;
    	for(int i=1;i<=n;i++){
    		cin>>a[i][1];
    		cin>>a[i][2];
    		cin>>a[i][3];
		}
		int t=0,k=1;
		for(int i=1;i<=n;i++){
			int w=ans;
			for(int j=1;j<=3;j++){
				if(b[j]<=n/2) ans=max(ans,w+a[i][j]);
				if(ans==w+a[i][j]) t=j;
				
				if(b[j]>n/2-1){
					if(a[k++][j]<a[i][j]){
						ans=ans-a[k-1][j]+a[i][j];
					}
				} 
				if(b[j]>n/2-1){
					ans=max(a[1][j],a[1][j+1]+a[2][j]);
				}
			}
			b[t]++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
