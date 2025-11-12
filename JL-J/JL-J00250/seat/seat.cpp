#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int aa[13][13];
    int sc[108];
    int n,m;
    cin>>n>>m;
    int l = n*m;
    for(int i=1;i<=l;i++){
        cin>>sc[i];
    }
    int r=sc[1];
    int under=1;
    sort(sc+1,sc+l+1);
    int score[108];
    for(int i=1;i<=l;i++){
        score[l-i+1]=sc[i];
    }
    for(int j=1;j<=m;j++){
        if(j%2==1){
            for(int i=1;i<=n;i++){
                aa[i][j]=score[under];
                under++;
            }
        }else{
            for(int i=n;i>=1;i--){
                aa[i][j]=score[under];
                under++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(aa[j][i]==r){
                cout<<i<<" "<<j<<endl;
            }
        }
    }

    return 0;
}
