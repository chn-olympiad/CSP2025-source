#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,b,c,id;
}a[100005];
int suma,sumb,sumc,numa,numb,numc,po;
int n;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;cin>>t;
    for(int q=1;q<=t;q++){
        cin>>n;
        int p=n/2;
        for(int i=1;i<=n;i++){
            cin>>a[i].a>>a[i].b>>a[i].c;
        }
        suma=0;sumb=0;sumc=0;numa=0;numb=0;numc=0;
        for(int i=1;i<=n;i++){
            int num=max(max(a[i].a,a[i].b),a[i].c);
            if(num==a[i].a){
                a[i].id=1;
                suma+=num;
                numa++;
            }
            else if(num==a[i].b){
                a[i].id=2;
                sumb+=num;
                numb++;
            }
            else{
                a[i].id=3;
                sumc+=num;
                numc++;
            }
            if(numa>p){
                int minn=INT_MAX;
                for(int j=1;j<=n;j++){
                    if(a[j].id==1){
                        minn=min(minn,a[j].a);
                    }
                }
                for(int j=1;j<=n;j++){
                    if(a[j].a==minn){
                        a[j].id=2;
                        numa--;
                        suma-=a[j].a;
                        numb++;
                        sumb+=a[j].b;
                    }
                }
            }
            if(numb>p){
                int minn=INT_MAX;
                for(int j=1;j<=n;j++){
                    if(a[j].id==2){
                        minn=min(minn,a[j].b);
                    }
                }
                for(int j=1;j<=n;j++){
                    if(a[j].b==minn){
                        a[j].id=3;
                        numb--;
                        sumb-=a[j].b;
                        numc++;
                        sumc+=a[j].c;
                    }
                }
            }
            if(numc>p){
                int minn=INT_MAX;
                for(int j=1;j<=n;j++){
                    if(a[j].id==3){
                        minn=min(minn,a[j].c);
                    }
                }
                for(int j=1;j<=n;j++){
                    if(a[j].c==minn){
                        a[j].id=1;
                        numc--;
                        sumc-=a[j].c;
                        numa++;
                        suma+=a[j].a;
                    }
                }
            }
            po=suma+sumb+sumc;
        }
        cout<<po<<endl;
    }
    return 0;
}
