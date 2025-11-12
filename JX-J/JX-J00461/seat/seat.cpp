#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,s,d;
    cin>>a>>s;
    int f[a*s];
    int g[a*s];
    for(int i=0;i<a*s;i++){
        cin>>f[i];
    }
    d=f[0];
    for(int i1=0;i1<a*s;i1++){
        int f1=0;
        int p;
        int io=0;
        for(;io<a*s;io++){
            if(f[io]==-1){
                continue;
            }
            else if(f[io]>f1){
                f1=f[io];
                p=io;
            }
        }
        f[p]=-1;
        g[i1]=f1;
    }
    for(int i=0;i<a*s;i++){
        if(i%(a*s)<a){
            if(d==g[i]){
                cout<<i/a+1<<' '<<i%s+a-1<<endl;
                break;

            }
        }
        else{
            if(d==g[i]){
                cout<<i/a+1<<' '<<s-(i%s)<<endl;
                break;
            }
        }

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
