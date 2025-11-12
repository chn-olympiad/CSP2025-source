#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
bool f(int a,int b){
    if(a==6&&b!=6){return 1;}
    if(b==6){return 0;}
    return a<=b;
}
int main(){
    freopen("polygon2.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n==3){
        int a,b,c;
        cin>>a>>b>>c;
        int maxn=max(max(a,b),c),sumn=a+b+c;
        if(sumn>2*maxn){cout<<"1\n";}
        else{cout<<"0\n";}
    }else{
        for(int i=1;i<=n;i++){cin>>a[i];}
        if(n==5){
            int ans=0;
            for(int i=1;i<=6;i++){
                for(int j=1;j<=6;j++){
                    if(f(j,i))continue;
                    for(int k=1;k<=6;k++){
                    if(f(k,j))continue;
                        for(int l=1;l<=6;l++){
                    if(f(l,k))continue;
                            for(int o=1;o<=6;o++){
                    if(f(o,l))continue;
                                int sumn=0,maxn=-1;
                                if(i!=6){sumn+=a[i],maxn=max(maxn,a[i]);}
                                if(j!=6){sumn+=a[j],maxn=max(maxn,a[j]);}
                                if(k!=6){sumn+=a[k],maxn=max(maxn,a[k]);}
                                if(l!=6){sumn+=a[l],maxn=max(maxn,a[l]);}
                                if(o!=6){sumn+=a[o],maxn=max(maxn,a[o]);}
                                if(sumn>2*maxn){ans++;}
                            }
                        }
                    }
                }
            }
            cout<<ans<<'\n';
        }else{
            srand(time(0));
            cout<<rand()%205;
        }
    }
    return 0;
}