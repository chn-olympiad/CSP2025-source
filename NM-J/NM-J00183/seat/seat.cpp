#include<bits/stdc++.h>
using namespace std;
int n,m;
int a1;
const int N = 200;
int f[N];
int f1[N][N];
bool cmp(int a,int b){
    return a > b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>f[0];
    a1 = f[0];
    for(int i = 1;i < n * m;i ++){
        cin>>f[i];
    }
    sort(f,f+n*m,cmp);
    int a = 0,b = 0;
    bool c = false;
    for(int i = 0;i < m;i){

        if(c == false){
                if(a == n){
                c = true;
                i++;
                a--;

                continue;
            }
            f1[a][i] = f[b];
            a++,b++;

        }
        if(c == true){
                if(a == -1){
                c = false;
                i++;
                a++;
                continue;
            }
            f1[a][i] = f[b];
            a--,b++;

        }

    }
    for(int i = 0;i < n;i ++){
        for(int j = 0;j < m;j ++){
            if(f1[i][j] == a1) cout<<j + 1<<" "<<i + 1;

        }

    }
    return 0;
}

