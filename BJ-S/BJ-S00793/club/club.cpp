#include<bits/stdc++.h>
using namespace std;
int a[1000100],b[1000111],c[1000010];
int nu=0,maaq=0,opo=0,miaq=0;
int aq,bq,cq;
int ek[1000010]={};
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    int am=-1,bm=-1,cm=-1;
    while(t--){
        int n;
        cin>>n;
        nu=0,opo=0;
        am=0,bm=0,cm=0,aq=0,bq=0,cq=0;
        for(int i=0;i<n;i++){
            cin>>a[i]>>b[i]>>c[i];
            //int km=-1;
            am=max(am,a[i]);
            bm=max(bm,b[i]);
            cm=max(cm,c[i]);
            if(max(a[i],max(b[i],c[i]))==a[i]){
                aq+=a[i];
            }
            if(max(a[i],max(b[i],c[i]))==b[i]){
                bq+=b[i];
            }
            if(max(a[i],max(b[i],c[i]))==c[i]){
                cq+=c[i];
            }
            //ek[i]=max(a[i],max(b[i],c[i]));
        }
        sort(a,a+n);
        sort(b,b+n);
        sort(c,c+n);
        maaq=max(aq,max(bq,cq));
        miaq=min(aq,min(bq,cq));
        if(maaq==aq){
            for(int i=0;i<n/2;i++){
                ek[i]=a[i+n/2];
            }
        }else if(maaq==bq){
            for(int i=0;i<n/2;i++){
                ek[i]=b[i+n/2];
            }
        }else if(maaq==cq){
            for(int i=0;i<n/2;i++){
                ek[i]=c[i+n/2];
            }
        }
        opo=bq+aq+cq;
        opo=opo-maaq-miaq;
        if(miaq==aq){
            for(int i=n/2;i<=n;i++){
                ek[i]=a[i+n/2];
            }
        }else if(miaq==bq){
            for(int i=n/2;i<=n;i++){
                ek[i]=b[i+n/2];
            }
        }else if(miaq==cq){
            for(int i=n/2;i<=n;i++){
                ek[i]=c[n/2+i];
            }
        }
        for(int i=n;i>=1;i--){
                nu+=ek[i];
        }
        cout<<nu<<endl;
    }
    return 0;
}
