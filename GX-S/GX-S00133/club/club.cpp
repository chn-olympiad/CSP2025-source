#include<bits/stdc++.h>
using namespace std;
long long syx[100],xx[100],axx[100],ss[100];
long long n,m,s,y,x,a,c,b;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>n;
    for(long long i=0;i<=n-1;i++){
        cin>>m;
        for(long long i1=0;i<=m-1;i++){
            cin>>a>>b>>c;
            syx[i1]=a;
            xx[i1]=b;
            axx[i1]=c;
        }
        for(int d=0;d<=m-1;d++){
            if(syx[d]>xx[d]&&syx[d]>axx[d]){
                x+=syx[d];
            }
            else if(xx[d]>syx[d]&&xx[d]>axx[d]){
                x+=xx[d];
            }
            else{
                x+=axx[d];
            }
            ss[s]=x;
            s++;
        }
    }
    for(int i=0;i<=m-2;i++){
        cout<<ss[i];
        cout<<endl;
    }
    return 0;
}

