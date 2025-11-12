#include<bits/stdc++.h>
using namespace std;
long long t,n,a[2*(10^5)][2*(10^5)];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        int grore=0,maxx=0;
        cin>>n;
        for(int j=1;j<=n;j++){
            for(int l=1;l<=3;l++){
                cin>>a[j][l];
            }
        }
        if(n==2){
            for(int j=1;j<=3;j++){
                for(int l=1;l<=3;l++){
                    if(l==j) continue;
                    if(l!=j){
                        if(a[1][j]+a[2][l]>maxx) maxx=a[1][j]+a[2][l];
                    }
                }
            }
            cout<<maxx<<endl;
        }
        if(n<=30 && n>2){
            for(int j=1;j<=n;j++){
                for(int l=1;l<=2;l++){
                    if(maxx<a[j][l]) maxx=a[j][l];
                }
                grore+=maxx;
            }
            cout<<grore<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
