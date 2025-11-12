#include<bits/stdc++.h>

using namespace std;

int n,m;
int flag;
int maps[11][11];
int mans[1000];
int z;//du qu lie jia qi

bool cmp(int x,int y){
    return x>y;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>mans[i];
    }
    flag=mans[0];
    sort(mans,mans+(n*m),cmp);
    //for(int i=0;i<n*m;i++){
    //    cout<<mans[i]<<" ";
    //}
    //cout<<endl;
    for(int i=0;i<m;i++){
        if((i+1)%2==1){
            for(int j=0;j<n;j++){
                if(flag==mans[z]){
                    cout<<i+1<<" "<<j+1<<endl;
                    return 0;
                }
                maps[j][i]=mans[z];
                z++;
            }
        }else{
            for(int j=n-1;j>=0;j--){
                if(flag==mans[z]){
                    cout<<i+1<<" "<<j+1<<endl;
                    return 0;
                }
                maps[j][i]=mans[z];
                z++;
            }
        }
    }
    //for(int i=0;i<n;i++){
    //    for(int j=0;j<m;j++){
    //        cout<<maps[i][j]<<" ";
    //    }
    //    cout<<endl;
    //}
    return 0;
}
