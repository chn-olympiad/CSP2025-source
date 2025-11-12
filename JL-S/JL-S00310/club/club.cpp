#include <bits/stdc++.h>
using namespace std;
struct node{
    int d1,d2,d3,id;
}a[100010];
struct clu{
    int id,num;
};
bool cmp1(clu x,clu y){
    //if(x.num!=y.num)return x.num<y.num;
    return x.num-max(a[x.id].d2,a[x.id].d3)<y.num-max(a[y.id].d2,a[y.id].d3);
}
bool cmp2(clu x,clu y){
    //(x.num!=y.num)return x.num<y.num;
    return x.num-max(a[x.id].d1,a[x.id].d3)<y.num-max(a[y.id].d1,a[y.id].d3);
}
bool cmp3(clu x,clu y){
    //if(x.num!=y.num)return x.num<y.num;
    return x.num-max(a[x.id].d2,a[x.id].d1)<y.num-max(a[y.id].d2,a[y.id].d1);
}
bool cmp4(clu a,clu b){
    return a.num<b.num;
}
bool cmp(int a,int b){
    return a<b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        long long ans=0;
        int n;
        cin>>n;
        clu clua[n+10],club[n+10],cluc[n+10];int aa=0,bb=0,cc=0;
        for(int i=0;i<n;i++){
            cin>>a[i].d1>>a[i].d2>>a[i].d3;
            a[i].id=i;
        }
        for(int i=0;i<n;i++){
            int mai;
            if(a[i].d1>=a[i].d2&&a[i].d1>=a[i].d3)mai=1;
            else if(a[i].d2>=a[i].d3&&a[i].d2>=a[i].d1)mai=2;
            else mai=3;
            if(mai==1){
                clua[aa].num=a[i].d1;clua[aa].id=i;aa++;
            }
            else if(mai==2){
                club[bb].num=a[i].d2;club[bb].id=i;bb++;
            }
            else{
                cluc[cc].num=a[i].d3;cluc[cc].id=i;cc++;
            }
        }
        //cout<<aa<<" "<<bb<<" "<<cc<<endl;
        if(aa>n/2){
            //cout<<"A is big!!\n";  // debug
            sort(clua,clua+aa,cmp1);
            for(int i=0;i<aa-n/2;i++){
                if(a[clua[i].id].d2>a[clua[i].id].d3){
                    club[bb].id=clua[i].id;club[bb].num=a[clua[i].id].d2;bb++;
                }
                else {
                    cluc[cc].id=clua[i].id;cluc[cc].num=a[clua[i].id].d3;cc++;
                }
                clua[i].num=0;
            }
        }
        else if(bb>n/2){
            //cout<<"B is big!!\n";  // debug
            sort(club,club+bb,cmp2);
            for(int i=0;i<bb-n/2;i++){
                if(a[club[i].id].d1>a[club[i].id].d3){
                    clua[aa].id=club[i].id;clua[aa].num=a[club[i].id].d1;aa++;
                    //printf("Now change %d to a\n",i);  //debug
                }
                else {
                    cluc[cc].id=club[i].id;cluc[cc].num=a[club[i].id].d3;cc++;
                    //printf("Now change %d to c\n",i);  //debug
                }
                club[i].num=0;
            }
        }
        else if(cc>n/2){
            //cout<<"C is big!!\n"; //debug
            sort(cluc,cluc+cc,cmp3);
            for(int i=0;i<cc-n/2;i++){
                if(a[cluc[i].id].d1>a[cluc[i].id].d2){
                    clua[aa].id=cluc[i].id;clua[aa].num=a[cluc[i].id].d1;aa++;
                }
                else {
                    club[bb].id=cluc[i].id;club[bb].num=a[cluc[i].id].d2;bb++;
                }
                cluc[i].num=0;
            }
        }
        for(int i=0;i<aa;i++)ans+=clua[i].num;
        for(int i=0;i<bb;i++)ans+=club[i].num;
        for(int i=0;i<cc;i++)ans+=cluc[i].num;
        cout<<ans<<endl;
    }
    return 0;
}
//1h21m 100pts!!!!!!!!!!
