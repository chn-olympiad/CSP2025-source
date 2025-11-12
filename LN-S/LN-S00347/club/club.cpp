#include<bits/stdc++.h>
using namespace std;
int t,n,c[5],ans;
    int l[5],m,m2;
}a[100005];
bool cmp(b x,b y){
return max({x.l[0],x.l[1],x.l[2]})>max({y.l[0],y.l[1],y.l[2]});}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){ans=0,c[0]=0,c[1]=0,c[2]=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i].l[0]>>a[i].l[1]>>a[i].l[2];
            if(a[i].l[0]>a[i].l[1])a[i].m=0;else a[i].m=1;
            if(a[i].l[a[i].m]<a[i].l[2])a[i].m=2;
            if(a[i].l[0]<a[i].l[1])a[i].m2=0;else a[i].m2=1;
            if(a[i].l[a[i].m2]>a[i].l[2])a[i].m2=2;}
        sort(a,a+n,cmp);
        for(int i=0;i<n;i++){
            if(c[a[i].m]<n/2)ans+=a[i].l[a[i].m],c[a[i].m]++;
            else ans+=a[i].l[3-a[i].m-a[i].m2],c[3-a[i].m-a[i].m2]++;
        }cout<<ans<<endl;
    }
    return 0;
}
