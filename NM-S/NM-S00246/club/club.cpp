#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,ans,a[N][5],cnt[3],mmax[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
                mmax[i]=max(mmax[i],a[i][j]);
            }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=3;j++){
                if(a[i][j]==mmax[i])
                cnt[j]++;
            }
    	for(int j=1;j<=3;j++){
			if(cnt[j]==n){
				sort(mmax+1,mmax+1+n);
				for(int k=n+1;k>=n/2+1;k--)
					ans+=mmax[k];
				break;
			}    		
    		else if(cnt[j]!=n&&cnt[j]!=0){
				for(int i=1;i<=n;i++)
					ans+=mmax[i];
				break;
			}
			else continue;
		}
		cout<<ans<<endl;
		memset(mmax,0,sizeof(mmax));
		memset(cnt,0,sizeof(cnt));
		memset(a,0,sizeof(a));	
		ans=0;
	}
    return 0;
}
