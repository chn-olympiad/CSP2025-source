#include <bits/stdc++.h>
using namespace std;
int f(int x,int y,int z,string s){
    int ansmax;
    int m=max(x,max(y,z));
    if(m==x){
        ansmax=1;
    }
    else if(m==y){
        ansmax=2;
    }
    else{
        ansmax=3;
    }
    m=min(x,min(y,z));
    int ansmin;
    if(m==z){
        ansmin=2;
    }
    else if(m==y){
        ansmin=1;
    }
    else{
        ansmin=0;
    }
    if(s=="max"){
        cout << ansmax;
    }
    else if(s=="min"){
        cout << ansmin;
    }
    else{
        cout << 3-ansmax-ansmin;
    }
}
int main(){
    freopen("club.in","cin",stdin);
    freopen("club.out","cout",stdout);
    int n;
    cin >> n;
    const int N=n;
    struct a{
        int a[3];
    }a[N];
    int b[3][N/2+1],l[3]={};
    b[0][N/2]=-1;
    b[1][N/2]=-1;
    b[2][N/2]=-1;
    for(int i=0;i<N;i++){
        cin >> a[i].a[0] >> a[i].a[1] >> a[i].a[2];
        if(b[f(a[i].a[0],a[i].a[1],a[i].a[2],"max")][l[f(a[i].a[0],a[i].a[1],a[i].a[2],"max")]]!=-1){
            b[f(a[i].a[0],a[i].a[1],a[i].a[2],"max")][l[f(a[i].a[0],a[i].a[1],a[i].a[2],"max")]]=i;
            l[f(a[i].a[0],a[i].a[1],a[i].a[2],"max")]++;
        }
        else{
            int min1=999999999,minlb=-1,minab=-1;
            for(int j=0;j<N/2;j++){
                int i1=b[f(a[i].a[0],a[i].a[1],a[i].a[2],"max")][j];
                if(a[b[f(a[i].a[0],a[i].a[1],a[i].a[2],"max")][j]].a[f(a[i1].a[0],a[i1].a[1],a[i1].a[2],"max")]-a[b[f(a[i].a[0],a[i].a[1],a[i].a[2],"max")][j]].a[f(a[i1].a[0],a[i1].a[1],a[i1].a[2],"mid")]<min1){
                    min1=a[b[f(a[i].a[0],a[i].a[1],a[i].a[2],"max")][j]].a[f(a[i1].a[0],a[i1].a[1],a[i1].a[2],"max")]-a[b[f(a[i].a[0],a[i].a[1],a[i].a[2],"max")][j]].a[f(a[i1].a[0],a[i1].a[1],a[i1].a[2],"mid")];
                    minlb=j;
                    minab=f(a[i1].a[0],a[i1].a[1],a[i1].a[2],"mid");
                }
            }
            if(a[i].a[f(a[i].a[0],a[i].a[1],a[i].a[2],"mid")] > a[i].a[f(a[i].a[0],a[i].a[1],a[i].a[2],"max")]-min1){
                b[f(a[i].a[0],a[i].a[1],a[i].a[2],"mid")][l[f(a[i].a[0],a[i].a[1],a[i].a[2],"mid")]]=i;
                l[f(a[i].a[0],a[i].a[1],a[i].a[2],"mid")]++;
            }
            else{
                b[minab][l[minab]]=b[f(a[i].a[0],a[i].a[1],a[i].a[2],"max")][minlb];
                b[f(a[i].a[0],a[i].a[1],a[i].a[2],"max")][minlb]=i;
                l[minab]++;
            }
        }
    }
    int ans=0;
    for(int j=0;j<3;j++){
        for(int i=0;i<=l[j];i++){
            if(b[j][i]+b[j][i+1]==0){
                break;
            }
            ans+=a[b[j][i]].a[f(a[b[j][i]].a[0],a[b[j][i]].a[1],a[b[j][i]].a[2],"max")];
        }
    }
    cout << ans;
    return 0;
}
