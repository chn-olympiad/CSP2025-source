#include<bits/stdc++.h>
using namespace std;
const int maxn=15;
long long a[maxn][maxn],b[maxn*maxn];
priority_queue<long long,vector<long long> >q;
long long n,m,c,r,tmp,x=1,y=1;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    for(long long i=1;i<=n*m;i++){
        cin>>b[i];
    }
    tmp=b[1];
    for(long long i=1;i<=n*m;i++){
        q.push(b[i]);
    }
    bool con=0;
    while(!q.empty()){
        a[x][y]=q.top();
        q.pop();
        if(a[x][y]==tmp){
            c=y;r=x;
            break;
        }
        if(con==0){
            if(x+1<=n)x++;
            else{
                y++;con=1;
            }
        }
        else{
            if(x-1>=1)x--;
            else{
                y++;con=0;
            }
        }
    }
    cout<<y<<" "<<x;
    return 0;
}
