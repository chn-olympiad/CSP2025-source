#include<bits/stdc++.h>
using namespace std;
int n,m,a[100],Rs,Rl,Rr;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    Rs=a[0];
    sort(a,a+n*m,cmp);
    for(int i=0;i<n*m;i++){
        if(a[i]==Rs){
            Rl=i/n;
            Rr=i%n;
            break;
        }
    }
    if(Rl%2==1){
        Rr=n-Rr-1;
    }
    Rl++;
    Rr++;
    cout<<Rl<<" "<<Rr;
    return 0;
}
