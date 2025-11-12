#include<bits/stdc++.h>
using namespace std;
int n,m,x,k;
int t[1000];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>t[i];
    }x=t[0];
    sort(t,t+n*m,cmp);
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                if(t[k]==x){
                    cout<<i<<" "<<j;
                    return 0;
                }
                k++;
            }
        }else{
            for(int j=1;j<=n;j++){
                if(t[k]==x){
                    cout<<i<<" "<<j;
                    return 0;
                }
                k++;
            }
        }

    }
    //290es1q0
    return 0;

}//#Shang4Shan3Ruo6Shui4
