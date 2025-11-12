#include<bits/stdc++.h>
using namespace std;
int mp[101][101];
int score[160];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>score[i];
    }
    int x=score[1];
    sort(score+1,score+n*m+1,greater<int>());
    /*for(int i=1;i<=n*m;i++){
        cout<<score[i]<<" ";
    }*/
    int p=0;
    for(int j=1;j<=n;j++){
        if(j%2==1){
            for(int i=1;i<=m;i++){
                p++;
                //cout<<i<<" "<<j<<" :";
                mp[i][j]=score[p];
                //cout<<mp[i][j]<<" ";
            }
            //cout<<endl;
        }else if(j%2==0){
            for(int i=m;i>=1;i--){
                p++;
                //cout<<i<<" "<<j<<" :";
                mp[i][j]=score[p];
                //cout<<mp[i][j]<<" ";
            }
            //cout<<endl;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]==x){

                cout<<j<<" "<<i;
                return 0;
            }
        }
    }

    return 0;
}
