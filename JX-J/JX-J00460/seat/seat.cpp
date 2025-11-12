#include<bits/stdc++.h>
using namespace std;
int m,n,f[10005],aa[10005],a,cv,nm;
int main(){
    freopen("seat,in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>m>>n;
    nm=m*n;
    for(int i=0;i<=nm;i++){
            cin>>f[i];
            i++;
    }
    a=f[0];
    for(int j=0;j<=nm;j++){
        aa[j]=0;
        for(int ii=0;ii<=nm;ii++){
            aa[j]=max(aa[j],f[ii]);
        }
        for(int jj=0;jj<=nm;jj++){
            if(f[jj]==aa[j]){
                f[jj]=0;
            }
        }
    }
    for(int as=0;as<=nm;as++){
        if(aa[as]==a){
            cv=as;
        }
    }
    int mm,nn;
    mm=cv/m;
    nn=cv%n;
    cout<<nn<<" "<<mm<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

