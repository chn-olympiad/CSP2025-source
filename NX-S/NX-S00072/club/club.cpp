#include<bits/stdc++.h>
using namespace std;
struct kk{
        long long a1,a2,a3,zj,zd;
}a[100005];
long long c1[100005],c2[100005],c3[100005];
void club(){
    long long n,x1=0,x2=0,x3=0,maxn=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].a1>>a[i].a2>>a[i].a3;
        if(a[i].a1>=a[i].a2&&a[i].a1>=a[i].a3){
            maxn+=a[i].a1;
            a[i].zd=a[i].a1;
            x1++;
            c1[x1]=i;
            if(a[i].a2>=a[i].a3)a[i].zj=a[i].a2;
            else a[i].zj=a[i].a3;
        }
        else if(a[i].a2>=a[i].a1&&a[i].a2>=a[i].a3){
            maxn+=a[i].a2;
            a[i].zd=a[i].a2;
            x2++;
            c2[x2]=i;
            if(a[i].a1>=a[i].a3)a[i].zj=a[i].a1;
            else a[i].zj=a[i].a3;
        }
        else if(a[i].a3>=a[i].a2&&a[i].a3>=a[i].a1){
            maxn+=a[i].a3;
            a[i].zd=a[i].a3;
            x3++;
            c3[x3]=i;
            if(a[i].a1>=a[i].a2)a[i].zj=a[i].a1;
            else a[i].zj=a[i].a2;
        }
    }
    if(x1<=n/2&&x2<=n/2&&x3<=n/2)cout<<maxn<<endl;
    else{
        if(x1>n/2){
            while(x1>n/2){
                long long min1=1e8,c;
                for(int i=1;i<=x1;i++){
                    long long cz=a[c1[i]].zd-a[c1[i]].zj;
                    if(cz<min1){
                        c=i;
                        min1=cz;
                    }
                }
                c1[c]=1e6;
                sort(c1+1,c1+x1+1);
                x1--;
                maxn-=min1;
            }
        }
        else if(x2>n/2){
            while(x2>n/2){
                long long min1=1e8,c;
                for(int i=1;i<=x2;i++){
                    long long cz=a[c2[i]].zd-a[c2[i]].zj;
                    if(cz<min1){
                        c=i;
                        min1=cz;
                    }
                }
                c2[c]=1e6;
                sort(c2+1,c2+x2+1);
                x2--;
                maxn-=min1;
            }
        }
        else if(x3>n/2){
            while(x3>n/2){
                long long min1=1e8,c;
                for(int i=1;i<=x3;i++){
                    long long cz=a[c3[i]].zd-a[c3[i]].zj;
                    if(cz<min1){
                        c=i;
                        min1=cz;
                    }
                }
                c3[c]=1e6;
                sort(c3+1,c3+x3+1);
                x3--;
                maxn-=min1;
            }
        }
        cout<<maxn<<endl;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        club();
    }
    return 0;
}
