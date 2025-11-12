#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll sorts,mine;

ll hang,lie;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    sorts = 1;
    cin>>n>>m;
    cin>>mine;
    for(int i = 1; i < n * m; i ++ ){
        ll tmp; cin >> tmp;
        if(tmp > mine ) {
                sorts ++;
        }

    }
    lie = sorts / n;
    hang = sorts % n;
    //cout<<sorts<<endl;
    if(hang == 0 ) {
        if(lie % 2 == 0 ) {
            hang = 1;
        } else {
            hang = n;
        }
    }else{
        lie++;
        if(lie %2 == 0){
            hang = n - hang+1;
        }
    }
    cout<<lie<<" "<<hang;
    cout<<'\n';
    return 0;
}
