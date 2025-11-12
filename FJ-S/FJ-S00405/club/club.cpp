#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,ans=0,maxn=0,i;
	int maxn1=0,maxn2=0;
	cin>>t;
	int a[10*10+10][5];
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(i=1;i<=n;i++){
			if(n==2){
				for(int j=1;j<=3;j++){
					int m;
					if(a[i][j]>maxn1){
						maxn1=a[i][j];
						m=j;
					}
					if(a[i+1][j]>maxn2&&j!=m){
						maxn2=a[i+1][j];
					}
				}
				ans=maxn1+maxn2;
				cout<<ans<<endl;
				break;
			}
			else if(n>=3){
				ans=a[i][1]+a[i][2]+a[i][3];
				if(ans>maxn){
					maxn=ans;
				}
				cout<<maxn<<endl;
				break;
			}
		}	
	}
	return 0;
}
