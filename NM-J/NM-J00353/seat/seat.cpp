#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
    return a > b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,m,R;
    cin>>n>>m>>R;
    int score[n*m-1];
    for(int i = 0;i < n*m-1;i++) cin>>score[i];
    sort(score,score+n*m-1,cmp);
    int l = 0,r = n*m-2;
    int mid;
    while(true){
        mid = l+(r-l)/2;
        if(l >= r) break;
        if(score[mid] > R){
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    mid = l+(r-l)/2;
    //cout<<mid;
    int x,y;
    x = mid/n;
    if(x%2 == 0){
        y = mid%n;
    }else{
        y = (n-1)-mid%n;
    }
    cout<<x+1<<' '<<y+1;
    return 0;
}
