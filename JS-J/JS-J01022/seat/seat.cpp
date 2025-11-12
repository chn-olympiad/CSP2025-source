#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 105;
struct node{
    int mark;
    int id;
    int x;
    int y;
}a[N];
int cmp(node a,node b){
    return a.mark > b.mark;
}
int n,m;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int cnt = n * m;
    for(int i = 1;i <= cnt;i++){
        cin>>a[i].mark;
        a[i].id = i;
    }
    sort(a + 1,a + cnt + 1,cmp);
    int turn = 1;
    int tmp = 1;
    for(int i = 1;i <= m;i++){
        if(i % 2 == 0){
            tmp = n;
        }
        else{
            tmp = 1;
        }
        for(int j = 1;j <= n;j++){
            if(i % 2 == 1){
                a[turn].x = i;
                a[turn].y = tmp;
                tmp++;
                turn++;
            }
            else{
                a[turn].x = i;
                a[turn].y = tmp;
                tmp--;
                turn++;
            }
        }
    }
    for(int i = 1;i <= cnt;i++){
        if(a[i].id == 1){
            cout<<a[i].x<<" "<<a[i].y;
            return 0;
        }
    }
    return 0;
}
