#include<bits/stdc++.h>
using namespace std;
long long t,n;
bool cmp(int x,int y){
    return x>y;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        long long tmp=n/2,ans=0,a[100000],b[100000],c[100000],xuan[100000],chong[4]={0,0,0,0};
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
        }
        for(int i=1;i<=n;i++){
            int maxn=max(a[i],max(b[i],c[i]));
            if(maxn==a[i]){
                ans+=a[i];
                xuan[i]=1;
            }
            else if(maxn==b[i]){
                ans+=b[i];
                xuan[i]=2;
            }
            else{
                ans+=c[i];
                xuan[i]=3;
            }
        }
        for(int i=1;i<=n;i++){
            chong[xuan[i]]++;
        }
        if(chong[1]>tmp||chong[2]>tmp||chong[3]>tmp){
            //cout<<tmp<<" "<<chong[1]<<" "<<chong[2]<<" "<<chong[3]<<" \n";
            int most=max(chong[1],max(chong[2],chong[3])),duo=most-tmp,shaoyu[100000],da;
            if(most==chong[1]) da=1;
            else if(most==chong[2]) da=2;
            else da=3;
            for(int i=1;i<=n;i++){
                if(xuan[i]==1&&da==1){
                    shaoyu[i]=min(a[i]-b[i],a[i]-c[i]);
                }
                else if(xuan[i]==2&&da==2) shaoyu[i]=min(b[i]-a[i],b[i]-c[i]);
                else if(xuan[i]==3&&da==3) shaoyu[i]=min(c[i]-a[i],c[i]-b[i]);
                else shaoyu[i]=30000;
            }
            sort(shaoyu+1,shaoyu+n+1);
            //for(int i=1;i<=n;i++) cout<<shaoyu[i]<<" ";
            //cout<<duo<<" ";
            for(int i=1;i<=duo;i++) ans=ans-shaoyu[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
