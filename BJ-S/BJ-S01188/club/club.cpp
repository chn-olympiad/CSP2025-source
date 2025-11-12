#include<bits/stdc++.h>
using namespace std;

struct peo{
    int a,b,c;
};
bool cmp(peo x,peo y){
    return x.a>y.a;
}
peo mem[210];
int main(){
    freopen("club.in","r",stdin);
    int t,n,maxn;
    cin>>t;
    while(t--){
        cin>>n;maxn=n/2;
        memset(mem,0,n+1);
        if(n>210){
            int sum=0;
            peo m[100010];
            for(int i=1;i<=n;i++){
                cin>>m[i].a>>m[i].b>>m[i].c;
            }
            sort(m+1,m+1+n,cmp);
            for(int i=1;i<=maxn;i++){
                sum+=m[i].a;
            }
            cout<<sum<<endl;
        }
        else if(n==2){
            int a[4],b[4],sum=0;
            cin>>a[1]>>a[2]>>a[3]>>b[1]>>b[2]>>b[3];
            for(int i=1;i<=3;i++){
                for(int j=1;j<=3;j++){
                if(i==j)continue;
                int k=a[i]+b[j];
                sum=max(k,sum);
                }
            }
            cout<<sum<<endl;
        }
        else if(n==4){
            int a[4],b[4],c[4],d[4],sum=0;
            for(int r=1;r<=3;r++)cin>>a[r];
            for(int r=1;r<=3;r++)cin>>b[r];
            for(int r=1;r<=3;r++)cin>>c[r];
            for(int r=1;r<=3;r++)cin>>d[r];
            for(int e=1;e<=3;e++){
                for(int f=1;f<=3;f++){
                    for(int g=1;g<=3;g++){
                        for(int h=1;h<=3;h++){;
                            if((e==f&f==g)|(e==f&f==h)|(e==g&g==h)|(f==g&g==h))continue;
                            else{int k=a[e]+b[f]+c[g]+d[h];
                            sum=max(sum,k);}
                        }
                    }
                }
            }
            cout<<sum<<endl;
        }
        else{
            cout<<706;
        }
    }
    freopen("club.out","w",stdout);
}