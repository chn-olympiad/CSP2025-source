#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[205];
int r_score;
bool cmp(int x,int y){
    return x>=y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>r_score;
    a[1]=r_score;
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+n*m+1,cmp);
    int idx=0;
    bool down=true;
    int cnt=0;
    for(int i=1;i<=m;i++){
         if(down){
         for(int j=1;j<=n;j++){
                cnt++;
            if(a[cnt]==r_score){
                cout<<i<<" "<<j;
                return 0;
            }
        }
        }
        else{
            for(int j=n;j>=1;j--){
                cnt++;
                if(a[cnt]==r_score){
                cout<<i<<" "<<j;
                return 0;
            }
            }
        }
        down=!down;
    }
    fclose(stdin);
    fclose(stdout);
}
