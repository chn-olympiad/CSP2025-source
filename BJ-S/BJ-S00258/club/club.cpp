#include<bits/stdc++.h>
using namespace std;
int t,n,s,a,b,c,ss;
struct ngsb{
    int aa1,aa2,aa3,m1;
}aa[100001];
struct sb{
    int bb1,bb2,bb3,m2;
    int b1=1,b2=2,b3=3;
}bb[100001];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        a=0;b=0;c=0;
        ss=0;
        cin>>n;
        for(int i=0;i<n;i++){
            s=0;
            bb[i].b1=1;
            bb[i].b2=2;
            bb[i].b3=3;
            cin>>aa[i].aa1>>aa[i].aa2>>aa[i].aa3;
            s=max(max(aa[i].aa1,aa[i].aa2),aa[i].aa3);
            aa[i].m1=s;
        }
        for(int i=0;i<n;i++){
            s=0;
            bb[i].bb1=aa[i].m1-aa[i].aa1;
            bb[i].bb2=aa[i].m1-aa[i].aa2;
            bb[i].bb3=aa[i].m1-aa[i].aa3;
            if(bb[i].bb1>bb[i].bb2){
                swap(bb[i].bb1,bb[i].bb2);
                swap(bb[i].b1,bb[i].b2);
            }
            if(bb[i].bb2>bb[i].bb3){
                swap(bb[i].bb2,bb[i].bb3);
                swap(bb[i].b2,bb[i].b3);
            }
            if(bb[i].bb1>bb[i].bb2){
                swap(bb[i].bb1,bb[i].bb2);
                swap(bb[i].b1,bb[i].b2);
            }
            s=max(max(bb[i].bb1,bb[i].bb2),bb[i].bb3);
            bb[i].m2=s;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(bb[j].m2<bb[j+1].m2){
                    swap(bb[j],bb[j+1]);
                    swap(aa[j],aa[j+1]);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(bb[i].b1==1&&a<n/2){
                ss+=aa[i].aa1;
                a++;
            }else if(bb[i].b1==2&&b<n/2){
                ss+=aa[i].aa2;
                b++;
            }else if(bb[i].b1==3&&c<n/2){
                ss+=aa[i].aa3;
                c++;
            }else if(bb[i].b2==1&&a<n/2){
                ss+=aa[i].aa1;
                a++;
            }else if(bb[i].b2==2&&b<n/2){
                ss+=aa[i].aa2;
                b++;
            }else if(bb[i].b2==3&&c<n/2){
                ss+=aa[i].aa3;
                c++;
            }else if(bb[i].b3==1&&a<n/2){
                ss+=aa[i].aa1;
                a++;
            }else if(bb[i].b3==2&&b<n/2){
                ss+=aa[i].aa2;
                b++;
            }else{
                ss+=aa[i].aa3;
                c++;
            }
        }
        cout<<ss<<"\n";
    }
    return 0;
}
