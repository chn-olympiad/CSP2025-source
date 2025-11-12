#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 11451;
struct node{
    int num;
    bool f;
};
node seat[N];
bool cmp(node l,node r){
    return l.num > r.num;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin.tie(0);
    cout.tie(0)->sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1 ; i <= n*m ; i++){
        cin >> seat[i].num;
        seat[i].f = 0;
    }
    seat[1].f = 1;
    sort(seat+1,seat+n*m,cmp);
   //for(int i = 1 ; i <= n*m ; i++){
   //        cout << seat[i].num<<endl;
    //}
    int goal;
    for(int i = 1 ; i <= n*m ; i++){
        if(seat[i].f == 1){
            goal = i;
            break;
        }
    }
    //cout << goal << endl;
    int g = ((goal-1)/n+1),h;
    if(g%2 == 0){
        h = n-(goal-(g-1)*n)+1;
    }
    else{
        h = (goal-(g-1)*n);
    }
    cout << g << ' ' << h << endl;
    return 0;
}
