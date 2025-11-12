#include<bits/stdc++.h>
using namespace std;
struct node{
    int d1,d2,d3;
}a[100005];
int dd1[100005],dd2[100005],dd3[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(dd1,0x3f,sizeof(dd1));
        memset(dd2,0x3f,sizeof(dd2));
        memset(dd3,0x3f,sizeof(dd3));
        int n,ans=0;
        cin>>n;
        int cnt[5]={};
        for(int i=1;i<=n;i++){
            cin>>a[i].d1>>a[i].d2>>a[i].d3;
            ans+=max({a[i].d1,a[i].d2,a[i].d3});
            if(a[i].d1>=a[i].d2&&a[i].d1>=a[i].d3){
                cnt[1]++;
                if(a[i].d2>=a[i].d3){
                    dd1[i]=a[i].d1-a[i].d2;
                }
                else{
                    dd1[i]=a[i].d1-a[i].d3;
                }
            }
            else if(a[i].d2>=a[i].d1&&a[i].d2>=a[i].d3){
                cnt[2]++;
                if(a[i].d1>=a[i].d3){
                    dd2[i]=a[i].d2-a[i].d1;
                }
                else{
                    dd2[i]=a[i].d2-a[i].d3;
                }
            }
            else{
                cnt[3]++;
                if(a[i].d1>=a[i].d2){
                    dd3[i]=a[i].d3-a[i].d1;
                }
                else{
                    dd3[i]=a[i].d3-a[i].d2;
                }
            }
        }
        int tot=max({cnt[1],cnt[2],cnt[3]});
        if(tot<=n/2){
            cout<<ans<<"\n";
        }
        else{
            if(cnt[1]==tot){
                sort(dd1+1,dd1+n+1);
                for(int i=1;i<=tot-n/2;i++){
                    ans-=dd1[i];
                }
                cout<<ans<<"\n";
            }
            else if(cnt[2]==tot){
                sort(dd2+1,dd2+n+1);
                for(int i=1;i<=tot-n/2;i++){
                    ans-=dd2[i];
                }
                cout<<ans<<"\n";
            }
            else{
                sort(dd3+1,dd3+n+1);
                for(int i=1;i<=tot-n/2;i++){
                    ans-=dd3[i];
                }
                cout<<ans<<"\n";
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
