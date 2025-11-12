#include<bits/stdc++.h>
using namespace std;
struct student{
    int sata,satb,satc,ig;
}sat[100001];
bool cmpa(student x,student y){
    return x.satb-x.sata>y.satb-y.sata;
}
bool cmpb(student x,student y){
    return x.satc-x.satb>y.satc-y.satb;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int n,hn,ga=0,gb=0,gc=0,ans=0,k;
        scanf("%d",&n);
        hn=n/2;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&sat[i].sata,&sat[i].satb,&sat[i].satc);
            if(sat[i].sata>=sat[i].satb&&sat[i].sata>=sat[i].satc) ga++;
            else if(sat[i].satb>=sat[i].sata&&sat[i].satb>=sat[i].satc) gb++;
            else if(sat[i].satc>=sat[i].sata&&sat[i].satc>=sat[i].satb) gc++;
            ans+=max(max(sat[i].sata,sat[i].satb),sat[i].satc);
        }
        sort(sat+1,sat+n+1,cmpa);
        k=0;
        while(ga>hn){
            k++;
            ga--;
            ans-=sat[k].sata-sat[k].satb;
            gb++;
            k++;
        }
        sort(sat,sat+n+1,cmpb);
        k=0;
        while(gb>hn){
            k++;
            gb--;
            ans-=sat[k].satb-sat[k].satc;
            gc++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
