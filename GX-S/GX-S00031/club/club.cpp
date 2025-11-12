#include<bits/stdc++.h>
using namespace std;
struct hh{
    int a1=0,a2=0,a3=0;
}a[100005];
int n,q1=0,q2=0,q3=0,sum=0;
hh b1[100000],b2[100000],b3[100000];
bool cmp1(hh x,hh y){
    return x.a1>y.a1;
}
bool cmp2(hh x,hh y){
    return x.a2>y.a2;
}
bool cmp3(hh x,hh y){
    return x.a3>y.a3;
}
int getans(){
        for(int i=1;i<=q1;i++){
            sum+=b1[i].a1;
        }
        for(int i=1;i<=q2;i++){
            sum+=b2[i].a2;
        }
        for(int i=1;i<=q3;i++){
            sum+=b3[i].a3;
        }
        return sum;

}
void ac(){
        for(int i=1;i<=q1;i++){
            b1[i].a1=0;b1[i].a2=0;b1[i].a3=0;
        }
        for(int i=1;i<=q2;i++){
            b2[i].a1=0;b2[i].a2=0;b2[i].a3=0;
        }
        for(int i=1;i<=q3;i++){
            b3[i].a1=0;b3[i].a2=0;b3[i].a3=0;
        }
}


void dfs1(int bh,bool x){
    if(!x)  dfs1(bh-1,1);
    if(bh<1) return;
    int nans;
    if(q2+1<n/2){
        q1--;q2++;
        swap(b1[bh],b2[q2]);
        nans=getans();
    }
    if(q3+1<n/2){
        q3++;
        swap(b2[q2],b3[q3]);
        if(nans>getans()){
            q3--;q2++;
            swap(b2[q2],b3[q3]);
        }
    }
    q1++;
    dfs1(bh,0);

    }

void dfs2(int bh,bool x){
    if(!x)  dfs2(bh-1,1);
    if(bh<1) return;
    int nans;
    if(q1+1<n/2){
        q2--;q1++;
        swap(b2[bh],b1[q1]);
        nans=getans();
    }
    if(q3+1<n/2){
        q3++;
        swap(b1[q1],b3[q3]);
        if(nans>getans()){
            q3--;
            swap(b1[q1],b3[q3]);
        }
        else {
            q1--;
        }
    }
    dfs2(bh,0);
    q2++;
    }

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T,data=1;
    cin>>T;
    while(T--){
        cin>>n;
        sum=0,q1=0,q2=0,q3=0;
        for(int i=1;i<=n;i++) cin>> a[i].a1 >> a[i].a2 >> a[i].a3;
        for(int i=1,j=0;i<=n;i++){
            if(a[i].a1==max(a[i].a1,max(a[i].a2,a[i].a3))){
                q1++;
                b1[q1]=a[i];
            }
            if(a[i].a2==max(a[i].a1,max(a[i].a2,a[i].a3))){
                q2++;
                b2[q2]=a[i];
            }
            if(a[i].a3==max(a[i].a1,max(a[i].a2,a[i].a3))){
                q3++;
                b3[q3]=a[i];
            }
        }
        sort(b1+1,b1+q1+1,cmp1);
        sort(b2+1,b2+q2+1,cmp2);
        sort(b3+1,b3+q3+1,cmp3);

        cout<<getans()<<endl;
        ac();
    }
    return 0;
}
