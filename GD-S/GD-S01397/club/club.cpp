#include<bits/stdc++.h>
using namespace std;
int t,n,b[100005],ans=0;
struct c{
    int a1,a2,a3;
};
c a[100005];

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin>>t;
    while(t--){
        bool f=true;
        int ans=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i].a1>>a[i].a2>>a[i].a3;
            b[i]=a[i].a1;
            if(a[i].a2!=0&&a[i].a3!=0){
                    f=false;
        }}
        if(f==true){
            sort(b,b+n);
            for(int i=n-1;i>=n/2;i--){
                ans+=b[i];
            }
            cout<<ans;

        }
    else{
            int anss;
        if(n==2){
            int ma=max(a[0].a1,a[1].a1),mb=max(a[0].a2,a[1].a2),mc=max(a[0].a3,a[1].a3);
            int md[4]={ma,mb,mc};
            sort(md,md+3);
            ans=md[1]+md[2];

        }
        cout<<ans;
}

    }

    return 0;
}
