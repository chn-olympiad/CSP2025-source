#include<bits/stdc++.h>
using namespace std;
int n,b[4],sum;
struct vo{
    int v;
    int nm;
    int f;
}a[10000000];
int cmp(vo x,vo z){
    return x.v<z.v;
}
int main(){
    int t;
    cin>>t;
     while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i].v;
                a[i].nm=j;
                a[i].f=i;
            }
        }
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                if(b[a[i].nm]<n/2&&a[i].f!=0){
                    sum+=a[i].v;
                    b[a[i].nm]++;
                    for(int v=1;v<=3*n;v++){
                        if(a[v].f==a[i].f){
                            a[v].f==0;
                        }
                    }
                    a[i].f=0;

                }
            }

        }
    cout<<sum;
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    return 0;
}

}
