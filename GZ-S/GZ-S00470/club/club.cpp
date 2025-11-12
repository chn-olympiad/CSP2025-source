//GZ-S00470 遵义天立学校 陈明鑫
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,a[N][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
    	int n,cnt=0,a1=0,a2=0,a3=0,ans=0;
    	cin>>n;
    	cnt=n>>1;
    	for(int i=1;i<=n;i++)
    		for(int j=1;j<=3;j++)
		        cin>>a[i][j];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(a1>cnt){
					if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
						a1++;
						ans+=a[i][1];
					}
				}
				if(a2>cnt){
					if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
						a2++;
						ans+=a[i][2];
					}
				}
				if(a3>cnt){
					if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
						a3++;
						ans+=a[i][3];
					}
				}
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}
