#include<iostream>
#include<queue>
using namespace std;
priority_queue<int> pq;
bool cmp(int a,int b){
    return a>b;
}
void func(int n,int m,int R){
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                if(pq.top()==R){
                    cout<<i<<" "<<j<<endl;
                    return;
                }
                pq.pop();
            }

        }
        else if(i%2==0){
            for(int j=n;j>=1;j--){
                if(pq.top()==R){
                    cout<<i<<" "<<j<<endl;
                    return;
                }
                pq.pop();
            }
        }
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int len=n*m;
    int R;
    for(int i=0;i<len;i++){
        int x;
        cin>>x;
        if(i==0) R=x;
        pq.push(x);
    }
    func(n,m,R);
    return 0;
}
