#include<bits/stdc++.h>
using namespace std;
int T;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int a[n+5],b[n+5],c[n+5];
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
        }
        sort(a+1,a+n+1,cmp);
        sort(b+1,b+n+1,cmp);
        sort(c+1,c+n+1,cmp);
        if(n==2){
            int ans1,ans2,ans3,ans4,ans5,ans6;
            ans1=a[1]+b[2];
            ans2=a[1]+c[2];
            ans3=b[1]+a[2];
            ans4=b[1]+c[2];
            ans5=c[1]+a[2];
            ans6=c[1]+b[2];
            cout<<max(ans1,max(ans2,max(ans3,max(ans4,max(ans5,ans6)))))<<'\n';
        }
        if(n==4){
            int ans1,ans2,ans3;
            ans1=a[1]+a[2]+b[1]+c[1];
            ans2=a[1]+b[1]+b[2]+c[1];
            ans3=a[1]+b[1]+c[1]+c[2];
            cout<<max(ans1,max(ans2,ans3))<<'\n';
        }
    }
    return 0;
}
