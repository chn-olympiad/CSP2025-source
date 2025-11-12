#include<bits/stdc++.h>
using namespace std;
int a[108]={0};
int oi[108];
int m,n,k,laojiu,jiulao;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=m*n;i++){
        cin>>k;
        if(i==1)laojiu=k;
        a[k]++;
    }
    int fla=0;
    for(int i=100;i>=1;i--){
        while(a[i]!=0){
            fla++;
            oi[fla]=i;
            a[i]--;
            if(oi[fla]==laojiu)jiulao=fla;
        }
    }
    int pjk=1;
    for(int i=1;i<=n;i++){
        if(i%2==1){
            for(int j=1;j<=m;j++){
                if(pjk==jiulao){
                    cout<<i<<" "<<j;
                    return 0;
                }
                pjk++;
            }
        }
        else if(i%2==0){
            for(int j=m;j>=1;j--){
                if(pjk==jiulao){
                    cout<<i<<" "<<j;
                    return 0;
                }
                pjk++;
            }
        }
    }
    return 0;
}
