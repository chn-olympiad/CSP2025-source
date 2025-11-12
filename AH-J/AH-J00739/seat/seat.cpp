#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n,a[11][11],b[122],c[122],d[122],i,j,s=0,p=1,k,v,x=1;
    cin>>n>>m;
    k=m*n;
    for(i=1;i<=k;i++){
        cin>>b[i];
        d[i]=b[i];
    }
    while(p<=k){
        for(i=1;i<=k;i++){
            if(b[i]>s) s=b[i],v=i;
        }
        b[v]=-1,c[p]=s,p++,s=0;
    }
    s=1,i=1,j=1,p=1;
    while(s<=k){
        a[i][j]=c[s];
        if(i==n&&p==0) j++,x=-1,p=1;
        else if(i==1&&p==0) j++,x=1,p=1;
        else i+=x,p=0;
        s++;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i][j]==d[1]){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
}
