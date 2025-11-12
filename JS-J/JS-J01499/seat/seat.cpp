#include <bits/stdc++.h>
#include <queue>
using namespace std;
const int N = 10+5;
int n,m,di[2] = {1,-1},p = 0;
struct Node{
    int score,id;
    bool operator<(Node nd)const { return score<nd.score;}
};
priority_queue <Node> q;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int d;
    for (int i = 1;i<= n*m;i++){
        cin>>d;
        q.push({d,i});
    }int i,s,x = 1,y = 1;
    while(!q.empty()){
        i = q.top().id;
        s = q.top().score;
        q.pop();
        if (i== 1){
            cout<<y<<' '<<x;
            break;
        }x+= di[p];
        if (x== n+1){
            p = 1;
            x = n;
            y++;
        }else if (x== 0){
            p = 0;
            x = 1;
            y++;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
