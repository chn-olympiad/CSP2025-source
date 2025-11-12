#include<bits/stdc++.h>
using namespace std;
int n,T;
struct nn{
    int i1,i2,i3,m1,m2,m3;
}c[100100];
struct n1{
    int id,k;
}y[11];
int a[100100][4];
bool cmp(nn a,nn b){
    if(a.i1==b.i1){
        if(a.m1==b.m1){
            if(a.m2==b.m2){
                return a.m3>b.m3;
            }else{
                return a.m2>b.m2;
            }
        }else{
            return a.m1>b.m1;
        }
    }else{
        return a.i1<b.i1;
    }
}
bool cm(n1 a,n1 b){
    return a.k>b.k;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> T;
    while(T--){
        cin >> n;
        memset(y,0,sizeof(y));
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin >> a[i][j];
                y[j].k=a[i][j];
                y[j].id=j;
            }
            sort(y+1,y+4,cm);
            c[i].m1=y[1].k,c[i].i1=y[1].id;
            c[i].m2=y[2].k,c[i].i2=y[2].id;
            c[i].m3=y[3].k,c[i].i3=y[3].id;
        }
        sort(c+1,c+1+n,cmp);
        //for(int i=1;i<=n;i++){
        //    cout << c[i].i1 << " " << c[i].m1 << endl;
        //}
        int l=0;
        int sum=0;
        int d=1,ff=0;
        for(int i=1;i<=n;i++){
            sum+=c[i].m1;
            if(c[i].i1==d){
                l++;
            }else{
                l=1;
                d++;
            }
            if(l>n/2){
                int f=0,h=0,kl=0,ui=0;
                for(int j=1;j<i;j++){
                    if(c[j].i1==c[i].i1){
                        if((c[j].m2+c[i].m1)>(c[j].m1+c[i].m2)){
                        f=1;
                        h=(c[j].m2+c[i].m1)-(c[j].m1+c[i].m2);
                        if(h>kl){
                            kl=h;
                            ui=j;
                        }
                        }
                    }
                }
                if(f==1){
                    sum-=c[ui].m1;
                    sum+=c[ui].m2;
                    swap(c[ui].i1,c[ui].i2);
                }else{
                    sum-=c[i].m1;
                    sum+=c[i].m2;
                    swap(c[i].i1,c[i].i2);
                }
            }
        }
        cout << sum << endl;
    }
}
