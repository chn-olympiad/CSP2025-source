#include <iostream>
using namespace std;

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    int seat[15][15]={0}, n, m, jl[105]={0}, ans;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>jl[i];
    }
    ans=jl[0];
    bool temp_y=1;
    int x=1, y=0;
    for(int i=0;i<n*m;i++){
        int max=-1, temp=0;
        for(int j=0;j<n*m;j++){
            if(jl[j]>max){
                max=jl[j];
                temp=j;
            }
        }
        if(temp_y){y++;} else{y--;}
        if(y>m){
            x++, y--;
            seat[x][y]=max;
            temp_y=0;
        }
        else if(y<1){
            x++, y++;
            seat[x][y]=max;
            temp_y=1;
        }
        else{
            seat[x][y]=max;
        }
        jl[temp]=-1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(seat[i][j]==ans){
                cout<<i<<' '<<j;
                break;
            }
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
