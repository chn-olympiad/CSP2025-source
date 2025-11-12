#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int s=n*m;
    for(int i=1;i<=s;i++){
        cin>>a[i];
    }
    int t=a[1],idx;
    sort(a+1,a+s+1);
    for(int i=1;i<=s;i++){
        if(a[i]==t){
           idx=i;
        }
    }
    idx=s-idx+1;
    int ansn=(idx-idx%n)/n,ansm=idx%n;
    if(idx%n!=0){
        ansn++;
    }
    if(idx%n==0){
        ansm=m;
    }
    if(ansn%2==0){
        ansm=m-ansm+1;
    }

    cout<<ansn<<" "<<ansm;
    return 0;
}
