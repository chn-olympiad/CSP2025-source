#include<bits/stdc++.h>
using namespace std;
long long n;
struct node{
    long long x,y,z;
}a[100005],a1[100005],a2[100005],a3[100005];
bool cmp1(node x,node y){
     return min((x.x-x.y),(x.x-x.z))>min((y.x-y.y),(y.x-y.z));
}
bool cmp2(node x,node y){
     return min((x.y-x.x),(x.y-x.z))>min((y.y-y.x),(y.y-y.z));
}
bool cmp3(node x,node y){
     return min((x.z-x.y),(x.z-x.x))>min((y.z-y.y),(y.z-y.x));
}
long long n1,n2,n3;
long long ans=0;
void solve(){
    if(n1>n/2){
        sort(a1+1,a1+n1+1,cmp1);
        while(n1>n/2){
            if(a1[n1].x-a1[n1].y<a1[n1].x-a1[n1].z){
                n2++;
                ans-=(a1[n1].x-a1[n1].y);
                n1--;
            }else{
                n3++;
                ans-=(a1[n1].x-a1[n1].z);
                n1--;
            }
        }
    }
    if(n2>n/2){
        sort(a2+1,a2+n2+1,cmp2);
        while(n2>n/2){
            if(a2[n2].y-a2[n2].x<a2[n2].y-a2[n2].z){
                n1++;
                ans-=(a2[n2].y-a2[n2].x);
                n2--;
            }else{
                n3++;
                ans-=(a2[n2].y-a2[n2].z);
                n2--;
            }
        }
    }
    if(n3>n/2){
        sort(a3+1,a3+n3+1,cmp3);
        while(n3>n/2){
            if(a3[n3].z-a3[n3].y<a3[n3].z-a3[n3].x){
                n2++;
                ans-=(a3[n3].z-a3[n3].y);
                n3--;
            }else{
                n1++;
                ans-=(a3[n3].z-a3[n3].x);
                n3--;
            }
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long _;
    cin>>_;
    while(_--){
        n1=0;
        n2=0;
        n3=0;
        ans=0;
        memset(a,0,sizeof(a));
        memset(a1,0,sizeof(a1));
        memset(a2,0,sizeof(a2));
        memset(a3,0,sizeof(a3));
        scanf("%lld",&n);
        for(long long i=1;i<=n;i++){
        scanf("%lld %lld %lld",&a[i].x,&a[i].y,&a[i].z);
        if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
            ans+=a[i].x;
            ++n1;
            a1[n1]={a[i].x,a[i].y,a[i].z};
        }else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
            ans+=a[i].y;
            ++n2;
            a2[n2]={a[i].x,a[i].y,a[i].z};
        }else{
            ans+=a[i].z;
            ++n3;
            a3[n3]={a[i].x,a[i].y,a[i].z};
        }
        }
        solve();
        cout<<ans<<endl;
    }
    return 0;
}
