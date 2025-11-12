#include <bits/stdc++.h>
using namespace std;
int n,m;
int k;
priority_queue <int ,vector<int> > a;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        int x;
        cin>>x;
        a.push(x);
        k=(i==1?x:k);
    }
    int x=0,y=1;
    while(!a.empty()){
        x=x+(!(y%2)?-1:1);
        y+=(x>n)||(x<1);
        x+=-(x>n);
        x+=(x<1);
        if(a.top()==k){
            cout<<y<<" "<<x;
            break;
        }
        a.pop();
    }
    return 0;
}
