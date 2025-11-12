#include<bits/stdc++.h>
using namespace std;
int reads[1000][1000];
bool cmp(a,c){
        if(a==true&&c==true){
            turn a>c;
        }

}
int main(){
    int n,m,b;
    cin>>n>>m;
    freopen(seat.in,'r',stdin);
    freopen(seat.out,'w',stdout);

    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            cin>>reads[i][j];
            b=reads[1][1];
            sort(reads+1,reads+1+n*m,cmp);
            if(b==reads[i][j]){
                cout<<reads[i][j];
            }
            back;

        }
    }
    return 0;
}
