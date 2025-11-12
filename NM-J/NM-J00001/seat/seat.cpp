#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stack>
using namespace std;
long long a[100] [100];
long long list[10000] ;
stack<long long>nn;
long long n,m,ss,i,j,k,h;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for( i = 1; i <= n * m; i++){
        cin>>list[i];
    }
    ss = list[1];
    sort(list+1,list+1+n * m);
    for(i = 1; i <= n*m; i++){
        nn.push(list[i]);
    }

    for( j = 1; j <= m; j++){
        if(j%2 == 1){
            for( k = 1; k <= n; k++){
                if(nn.empty()!=true)
                    a[k][j] = nn.top();
                    nn.pop();
            }
        }
        else{
            for( h = n; h >= 1; h--){
                if(nn.empty()!=true)
                    a[h][j] = nn.top();
                    nn.pop();
            }
        }
    }
    for( i = 1; i <= 11; i++) {
        for( j = 1; j <= 11;j++) {
            if(a[i][j] == ss){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
