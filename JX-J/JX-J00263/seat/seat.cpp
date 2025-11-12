#include<bits/stdc++.h>
using namespace std;
const int N=15;
const int M=15;
const int V=110;
int n,m;
int u;
int cj[N*M];
priority_queue<int> q;
int zd[2];
int dx[2]={1,-1};
int dir;
int x=1,y=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>m;
    zd[0]=n;
    zd[1]=1;
    //U=94
    //100 99 98 97 96 95 94 93 92
    //(1,1) (2,1) (3,1) (2,2)
    for(int i=1;i<=n*m;i++){
        cin>>cj[i];
        q.push(cj[i]);
    }
    u=cj[1];

    while(q.size()){
        if(q.top()==u){
            cout<<y<<' '<<x;
            break;
        }

        //cout<<x<<' '<<y<<'\n';

        if(x==zd[dir]){
            dir^=1;
            y++;
            q.pop();
            continue;
        }
        x+=dx[dir];
        q.pop();
    }
	return 0;
}

