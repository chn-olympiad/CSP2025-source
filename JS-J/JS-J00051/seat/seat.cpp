#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,r;
int cnt;
priority_queue<int,vector<int>,less<int>> q;
int R;
int face;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>c>>r;
    int num=c*r;
    cin>>cnt;
    R=cnt;
    q.push(cnt);
    for(int i=1;i<num;i++){
        cin>>cnt;
        q.push(cnt);
    }
    int a=0,b=1;
    while(q.size()){
        if(face==0)a++;
        if(face==1)a--;
        if(a>c)a--,b++,face=1;
        if(a<1)a++,b++,face=0;
        if(q.top()==R){
            cout<<b<<' '<<a;
            return 0;
        }
        q.pop();
    }
    return 0;
}
