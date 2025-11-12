#include <bits/stdc++.h>

using namespace std;

struct P{
    int prf, sat, osa;
};
struct M{
    int sat, osa;
};
struct U{
    int ind, sat;
};
P lst[100000];
M mlst[100000];
U u[3];
int a[3];
int hax[3];
bool cu(U x, U y){
    return x.sat>y.sat;
}
bool cm(M x, M y){
    return x.osa>y.osa;
}
void cinp(int ind){
    for(int i=0; i<3; i++){
        u[i].ind=i;
        u[i].sat=a[i];
    }
    sort(u, u+3, cu);
    lst[ind].prf=u[0].ind;
    lst[ind].sat=u[0].sat;
    lst[ind].osa=u[0].sat-u[1].sat;
}

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T, n, id, sum;
    int mpi;
    bool f;
    cin>>T;
    while(T--){

    sum=0;
    id=0;
    f=0;
    for(int i=0; i<3; i++){
        hax[i]=0;
    }
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin>>a[j];
        }
        cinp(i);
        hax[lst[i].prf]++;
    }
    for(int i=0; i<3; i++){
        if(hax[i]>n/2){
            f=1;
            mpi=i;
        }
    }
    if(f==0){
        for(int i=0; i<n; i++){
            sum+=lst[i].sat;
        }
    }else{
        for(int i=0; i<n; i++){
            if(lst[i].prf==mpi){
                mlst[id].sat=lst[i].sat;
                mlst[id].osa=lst[i].osa;
                id++;
            }else{
                sum+=lst[i].sat;
            }
        }
        sort(mlst, mlst+id, cm);
        for(int i=0; i<n/2; i++){
            sum+=mlst[i].sat;
        }
        for(int i=n/2; i<id; i++){
            sum+=mlst[i].sat-mlst[i].osa;
        }
    }
    cout<<sum<<endl;

    }
    return 0;
}
