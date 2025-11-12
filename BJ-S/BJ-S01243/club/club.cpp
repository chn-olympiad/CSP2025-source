#include<bits/stdc++.h>
using namespace std;
struct S{
    long long a[3];
    long long m[3];
    long long sub;
}a[100000];
bool cmp(S m,S n){
    return m.sub>n.sub;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long T;
    cin>>T;
    while(T--){
        long long i,t,j,k,n,s[3]={0,0,0},ans=0;
        cin>>n;
        for(i=0;i<n;i++)cin>>a[i].a[0]>>a[i].a[1]>>a[i].a[2];
        for(i=0;i<n;i++){
            t=max(a[i].a[0],max(a[i].a[1],a[i].a[2]));
            if(t==a[i].a[0]){
                a[i].m[0]=0;
                if(a[i].a[1]>=a[i].a[2]){
                    a[i].m[1]=1;
                    a[i].m[2]=2;
                }else{
                    a[i].m[1]=2;
                    a[i].m[2]=1;
                }
            }
            if(t==a[i].a[1]){
                a[i].m[0]=1;
                if(a[i].a[0]>=a[i].a[2]){
                    a[i].m[1]=0;
                    a[i].m[2]=2;
                }else{
                    a[i].m[1]=2;
                    a[i].m[2]=0;
                }
            }
            if(t==a[i].a[2]){
                a[i].m[0]=2;
                if(a[i].a[1]>=a[i].a[0]){
                    a[i].m[1]=1;
                    a[i].m[2]=0;
                }else{
                    a[i].m[1]=0;
                    a[i].m[2]=1;
                }
            }
            a[i].sub=a[i].a[a[i].m[0]]-a[i].a[a[i].m[1]];
        }sort(a,a+n,cmp);
        for(i=0;i<n;i++){
            if(s[a[i].m[0]]<n/2){
                s[a[i].m[0]]++;
                ans+=a[i].a[a[i].m[0]];
            }else{
                s[a[i].m[1]]++;
                ans+=a[i].a[a[i].m[1]];
            }
        }cout<<ans<<endl;
    }
}
