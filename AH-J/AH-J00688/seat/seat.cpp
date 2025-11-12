#include<bits/stdc++.h>
using namespace std;
long long a[20][20],b;
priority_queue<long long> q;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            q.push(a[i][j]);
            if(i==1&&j==1){
                b=a[i][j];
            }
        }
    }
    bool up=0;
    int j=1;
    while(1){
        if(up==0){
            for(int i=1;i<=m;){
                    if(q.top()==b){
                        cout<<j<<" "<<i;
                        return 0;
                    }
                    q.pop();
                    i++;
                    if(i>m){
                        up=1;
                        j++;
                        break;
                    }
            }
        }
        else{
            for(int i=m;i>=1;){
                    if(q.top()==b){
                        cout<<j<<" "<<i;
                        return 0;
                    }
                    q.pop();
                    i--;
                    if(i<1){
                        up=0;
                        j++;
                        break;
                    }
            }
        }
    }
    return 0;
}

