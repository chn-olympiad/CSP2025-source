#include <bits/stdc++.h>
using namespace std;
struct aj{
    int x[3];
    int y;
};
bool cmp(aj a,aj b){
    if(a.y!=b.y){
        return a.y>b.y;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,m;
    int b[4]={0},v;
    cin>>n;
    int h=0;
    int c1,c2,c3;
    aj a[50005];
    for(int i=0;i<n;++i){
        cin>>m;
        c1=m/2;
        c2=m/2;
        c3=m/2;
        h=0;
        int o=1;
        for(int j=0;j<m;++j){
            cin>>a[j].x[0]>>a[j].x[1]>>a[j].x[2];
            a[j].y=a[j].x[0]+a[j].x[1]+a[j].x[2];
        }
        int sum=0,sam=0,kk=0,t2,s,t1,s1;
        for(int t=0;t<m;t+=2){


          for(int j=0;j<3;j++){
            for(int l=0;l<3;++l){
                sum=a[t].x[j]+a[t+1].x[l];
                t2=a[t].x[j];
                s=a[t+1].x[l];
                if(sam<sum){
                    sam=sum;
                    t1=t2;
                    s1=s;
                }
            }
           }
           kk+=sam;
      cout<<kk<<endl;
       }
    }
    return 0;
}
