#include<bits/stdc++.h>
using namespace std;
using ll=long long;
double a[105];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;cin>>n>>m;
    int N=n*m;
    for(int i=1;i<=N;i++){
        cin>>a[i];
    }
    int score=a[1];
    sort(a+1,a+N+1);
    int place=0;
    for(int i=1;i<=N;i++){
        if(a[i]==score) place=N-i;
    }
    int x=1,y=1;
    string s="down";
    while(place){
        place--;
        if(s=="down"){
            if(x>=n){
                s="up";
                y++;
            }else{
                x++;
            }
        }else{
            if(x<=1){
                s="down";
                y++;
            }else{
                x--;
            }
        }
    }
    cout<<y<<' '<<x;
    return 0;
}