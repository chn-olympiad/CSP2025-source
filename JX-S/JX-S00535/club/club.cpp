#include<bits/stdc++.h>
using namespace std;
int t,n,sum1,sum2,sum3,a[100010],b[100010],c[100010],p,o;
bool e=1,r=1;
struct node{
    int d,k;
}s[50010];
bool cmp(node xx,node yy){
    return xx.d+b[yy.k]<yy.d+b[xx.k];
}
struct node1{
    int d,k;
}s1[50010];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        e=1;r=1;sum2=0,sum1=0;
        int sum=0,maxn=0;
        cin>>n;
        if(n==2){
            int a[3],b[3],q,w;
            cin>>a[0]>>a[1]>>a[2]>>b[0]>>b[1]>>b[2];
            maxn=max(a[0]+b[1],a[0]+b[2]);
            maxn=max(maxn,max(a[1]+b[0],a[1]+b[2]));
            maxn=max(maxn,max(a[2]+b[0],a[2]+b[1]));
        }else{
            for(int i=1;i<=n;i++){
                cin>>a[i]>>b[i]>>c[i];
                if(b[i]==0) e=1;
                else if(c[i]==0){
                    e=0;
                    r=1;
                }else r=0;
            }
            if(e){
                sort(a+1,a+1+n);
                for(int i=(n/2)+1;i<=n;i++){
                    maxn+=a[i];
                }
            }else{
                for(int i=1;i<=n;i++){
                    if(sum1<n/2){
                        sum1++;
                        s[sum1].d=a[i];
                        s[sum1].k=i;
                        sort(s+1,s+1+sum1,cmp);
                    }else{
                        if(b[s[1].k]+a[i]>=b[i]+s[1].d){
                            o=s[1].k;
                            s[1].d=a[i];
                            s[1].k=i;
                            sum2++;
                            s1[sum2].d=b[o];
                            s1[sum2].k=o;
                            sort(s+1,s+1+sum1,cmp);
                        }else{
                            sum2++;
                            s1[sum2].d=b[i];
                            s1[sum2].k=i;
                        }
                    }
                }
                for(int i=1;i<=sum1;i++){
                    maxn+=s[i].d+s1[i].d;
                }
            }
        }
        cout<<maxn<<"\n";
    }
    return 0;
}
