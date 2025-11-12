#include<bits/stdc++.h>
using namespace std;
int Map[15][15],N=0,M=0,A[250];
bool cmp(int X,int Y){
    return X>Y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>N>>M;
    int X=N*M;
    for(int i=0;i<X;i++){
        cin>>A[i];
    }
    int Score=A[0];
    sort(A,A+X,cmp);
    int Idx=0;
    for(int j=0;j<M;j+=0){
        for(int i=0;i<N;i++){
            Map[j][i]=A[Idx];
            Idx++;
        }
        j++;
        for(int i=N-1;i>=0;i--){
            Map[j][i]=A[Idx];
            Idx++;
        }
        j++;
    }
    for(int j=0;j<M;j++){
        for(int i=0;i<N;i++){
            if(Map[j][i]==Score) cout<<j+1<<' '<<i+1;
        }
    }
    return 0;
}
