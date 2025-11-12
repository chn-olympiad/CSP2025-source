#include<bits/stdc++.h>
using namespace std;
int a[10000][10000],b[10000];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    cin>>t;
    for(int k=1;k<=t;k++){
    	cin>>n;
    	b[k]=n;
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=3;j++){
    			cin>>a[i][j];
			}
		}
	}
	for(int i=1;i<=t;i++){
		int o,ans;
		if(b[i]==2||b[i]==4){
			if(b[i]==2){
				o=max(a[1][1]+a[2][2],o);
				o=max(a[1][1]+a[2][3],o);
				o=max(a[1][2]+a[2][1],o);
				o=max(a[1][2]+a[2][3],o);
				o=max(a[1][3]+a[2][1],o);
				o=max(a[1][3]+a[2][2],o);
				ans=ans+o;
			}
			if(b[i]==4){
				o=max(a[1][1]+a[2][1]+a[3][3]+a[4][3],o);
				o=max(a[1][1]+a[2][1]+a[3][3]+a[4][2],o);
				o=max(a[1][1]+a[2][1]+a[3][2]+a[4][3],o);
				o=max(a[1][1]+a[2][1]+a[3][2]+a[4][2],o);
				o=max(a[1][1]+a[2][2]+a[3][1]+a[4][3],o);
				o=max(a[1][1]+a[2][2]+a[3][2]+a[4][3],o);
				o=max(a[1][1]+a[2][2]+a[3][1]+a[4][1],o);
				o=max(a[1][1]+a[2][2]+a[3][1]+a[4][3],o);
				o=max(a[1][1]+a[2][2]+a[3][3]+a[4][2],o);
				o=max(a[1][1]+a[2][2]+a[3][1]+a[4][2],o);
				o=max(a[1][1]+a[2][2]+a[3][2]+a[4][1],o);
				o=max(a[1][1]+a[2][3]+a[3][1]+a[4][2],o);
				o=max(a[1][1]+a[2][3]+a[3][1]+a[4][3],o);
				o=max(a[1][1]+a[2][3]+a[3][2]+a[4][1],o);
				o=max(a[1][1]+a[2][3]+a[3][1]+a[4][2],o);
				o=max(a[1][1]+a[2][3]+a[3][3]+a[4][1],o);
				o=max(a[1][1]+a[2][3]+a[3][1]+a[4][3],o);
				o=max(a[1][2]+a[2][1]+a[3][3]+a[4][3],o);
				o=max(a[1][2]+a[2][1]+a[3][3]+a[4][2],o);
				o=max(a[1][2]+a[2][1]+a[3][1]+a[4][2],o);
				o=max(a[1][2]+a[2][1]+a[3][1]+a[4][3],o);
				o=max(a[1][2]+a[2][1]+a[3][3]+a[4][3],o);
				o=max(a[1][2]+a[2][2]+a[3][3]+a[4][3],o);
				o=max(a[1][2]+a[2][2]+a[3][1]+a[4][1],o);
				o=max(a[1][2]+a[2][2]+a[3][3]+a[4][1],o);
				o=max(a[1][2]+a[2][2]+a[3][1]+a[4][3],o);
				ans+=o;
			}
		}
		cout<<ans<<endl;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
