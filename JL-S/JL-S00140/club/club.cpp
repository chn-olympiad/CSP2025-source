#include<bits/stdc++.h>
using namespace std;
int t,n,an[11000][6];
int ans;
int how_much_club[6];
void find_wanted(int x,int y,int san){
    if(how_much_club[y]>n/2){
        return ;
    }
    if(x>n){
        ans=max(ans,san);
        return ;
    }
    san+=an[x][y];
    for(int i=1;i<=3;i++){
        how_much_club[i]++;
        find_wanted(x+1,i,san);
        how_much_club[i]--;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int j=1;j<=t;j++){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>an[i][j];
            }
        }
        ans=0;
        for(int i=1;i<=3;i++){
            how_much_club[i]=0;
        }
        find_wanted(0,0,0);
        cout<<ans<<endl;
    }
}
