#include<bits/stdc++.h>
using namespace std;
long long ts,n,ans,t1,t2,t3;
long long a[100005][4],t[100005][4],c[100005][4];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>ts;
    while(ts--){
        cin>>n;
        ans=0;t1=0;t2=0;t3=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][1]){
                ans+=a[i][1];
                t1++;
                t[t1][1]=i;
                c[i][2]=a[i][1]-a[i][2];
                c[i][3]=a[i][1]-a[i][3];
            }else if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][2]){
                ans+=a[i][2];
                t2++;
                t[t2][2]=i;
                c[i][1]=a[i][2]-a[i][1];
                c[i][3]=a[i][2]-a[i][3];
            }else{
                ans+=a[i][3];
                t3++;
                t[t3][3]=i;
                c[i][1]=a[i][3]-a[i][1];
                c[i][2]=a[i][3]-a[i][2];
            }
        }
        if(t1>n/2){
            long long y1=t1-n/2;
            long long yy1[100005];
            for(int i=1;i<=t1;i++){
                yy1[i]=min(c[t[i][1]][2],c[t[i][1]][3]);
            }
            sort(yy1+1,yy1+t1+1);
            for(int i=1;i<=y1;i++){
                ans-=yy1[i];
            }
            cout<<ans<<endl;
            continue;
        }else if(t2>n/2){
            long long y2=t2-n/2;
            long long yy2[100005];
            for(int i=1;i<=t2;i++){
                yy2[i]=min(c[t[i][2]][1],c[t[i][2]][3]);
            }
            sort(yy2+1,yy2+t2+1);
            for(int i=1;i<=y2;i++){
                ans-=yy2[i];
            }
            cout<<ans<<endl;
            continue;
        }else{
            long long y3=t3-n/2;
            long long yy3[100005];
            for(int i=1;i<=t3;i++){
                yy3[i]=min(c[t[i][3]][1],c[t[i][3]][2]);
            }
            sort(yy3+1,yy3+t3+1);
            for(int i=1;i<=y3;i++){
                ans-=yy3[i];
            }
            cout<<ans<<endl;
            continue;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
