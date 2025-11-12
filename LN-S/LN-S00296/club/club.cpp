#include<bits/stdc++.h>
using namespace std;
long long q[100009];
long long w[100009];
long long e[100009];
long long y[100000];
int main(){
    freopen("club.in","r","stdin");
    freopen("club.out","w","stdout");
    int n,t,a,b,c,d=0;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>a>>b>>c;
            q[j]=a;
            w[j]=b;
            e[j]=c;
            for(int i=1;i<=n;i++){
                if(q[j]>w[j] && q[j]>e[j]){
                    d+=q[j];
                }else if(q[j]<w[j] && w[j]>e[j]){
                    d+=w[j];
                }else if(w[j]<e[j] && e[j]>w[j]){
                    d+=e[j];
                }
            }
            y[i-1]=d-2;
            d=0;
        }
    }
    for(int i=0;i<=t-1;i++){
        cout<<y[i]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
