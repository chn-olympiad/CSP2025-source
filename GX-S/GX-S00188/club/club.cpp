#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e5+5;
queue<int>a1;
queue<int>a2;
queue<int>a3;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    ll n,t;
    cin>>t;
    while(t--){
    cin>>n;
    ll a[M]={0},b[M]={0},c[M]={0},d[M]={0};
    int minn[4]={0},maxx[4]={0},mid[4]={0};
    for(int i=1;i<=n;i++){
    cin>>a[i]>>b[i]>>c[i];
    d[i]=a[i];
							}
    if(n==2){

       for(int i=1;i<=n;i++)
       {
           if(a[i]<=b[i]&&a[i]<=c[i])
           {
               minn[i]=a[i];
                if(b[i]<=c[i]){
                    mid[i]=b[i];
                    maxx[i]=c[i];
                }
                else{
                maxx[i]=b[i];
                mid[i]=c[i];
                }
           }
           if(a[i]>=b[i]&&a[i]<=c[i]){
                mid[i]=a[i];
                if(b[i]<=c[i]){
                    maxx[i]=c[i];
                    minn[i]=b[i];
                }
                else{
                minn[i]=b[i];
                mid[i]=c[i];
                }
           }
           if(a[i]>=b[i]&&a[i]>=c[i]){
            maxx[i]=a[i];
            if(b[i]<=c[i]){
                minn[i]=b[i];
                mid[i]=c[i];
            }
            else{
               mid[i]=b[i];
                minn[i]=c[i];
            }
           }
       }
       if(maxx[1]==a[1]&&maxx[2]==a[2]||maxx[1]==b[1]&&maxx[2]==b[2]){
        cout<<max(maxx[1]+mid[2],maxx[2]+mid[1])<<endl;
        
       }
       else{
        cout<<maxx[1]+maxx[2]<<endl;
   
        }
    }
    else{
        int x=1;
        for(int i=1;i<=n;i++){
            if(c[i]!=0&&b[i]==0||c[i]==0&&b[i]!=0||c[i]!=0&&b[i]!=0){
                x=2;
            }
        }
        if(x==1){
            sort(d+1,d+n+1);
            ll ans=0;
            for(int i=n;i>n/2;i--){
                ans+=d[i];
            }
            cout<<ans<<endl;
        }
		else{
			for(int i=1;i<=n;i++){
				maxx[i]=max(a[i],max(b[i],c[i]));
		   }
		ll cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=maxx[i];
		}
		cout<<cnt<<endl;
     }
	}
	}
    return 0;
}
