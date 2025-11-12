#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

struct node{
    long long biggest,bn,secondbig,sn;
}k[111111];

long long T,n,n1,n2,n3,num1,num2,num3;
long long bm[5],num[5];

bool cmp(node x,node y){
    return x.biggest-x.secondbig>y.biggest-y.secondbig || (x.biggest-x.secondbig==y.biggest-y.secondbig && x.biggest>y.biggest);
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    for(int tT=1;tT<=T;tT++){
        cin>>n;
        for(int a=1;a<=3;a++){
            bm[a]=0;
            num[a]=0;
        }
        for(int a=1;a<=n;a++){
            cin>>n1>>n2>>n3;
            num1=1;
            num2=2;
            num3=3;
            if(n3>n2){
                swap(n3,n2);
                swap(num3,num2);
            }
            if(n2>n1){
                swap(n2,n1);
                swap(num2,num1);
            }
            if(n3>n2){
                swap(n3,n2);
                swap(num3,num2);
            }
            k[a].biggest=n1;
            k[a].bn=num1;
            k[a].secondbig=n2;
            k[a].sn=num2;
        }
        sort(k+1,k+n+1,cmp);
        for(int a=1;a<=n;a++){
            if(bm[k[a].bn]<n/2){
                bm[k[a].bn]++;
                num[k[a].bn]+=k[a].biggest;
            }else{
                bm[k[a].sn]++;
                num[k[a].sn]+=k[a].secondbig;
            }
        }
        cout<<num[1]+num[2]+num[3]<<endl;
    }
}
