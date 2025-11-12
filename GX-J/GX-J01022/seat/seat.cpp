#include<bits/stdc++.h>
using namespace std;

int seat_ls[11][11];
int a[105];

bool compare(int x, int y){
    return x>y;
}

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=n*m; i++){
        cin>>a[i];
    }
    int xiaoR = a[1];
    sort(a+1, a+n*m+1, compare);
    bool goback = false;
    int lie=1, hang=0, c=0;
    for(; lie<=m; lie++){
        for(;;){
            if(goback) hang--; else hang++;
            if((goback && hang==0) || (!goback && hang==n+1)) break;
            c++;
            if(a[c]==xiaoR){
                cout<<lie<<" "<<hang;
                return 0;
            }

        }
        goback=!goback;
    }
}
