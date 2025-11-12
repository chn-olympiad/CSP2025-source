#include <bits/stdc++.h>
using namespace std;
bool abc(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector <int> a;
    for(int i=0;i<n*m;i++){
        int sb;
        cin>>sb;
        a.push_back(sb);
    }
    int s=a[0],sx;
    sort(a.begin(),a.begin()+n*m,abc);
    for(int i=0;i<n*m;i++){
        if(a[i]==s){
            sx=i+1;
            break;
        }
    }
    if(sx<n){
        cout<<1<<' '<<sx;
    }
    else{
        if(sx%n==0){
            if((sx/n)%2==0) cout<<sx/n<<' '<<1;
            else cout<<sx/n<<' '<<n;
        }
        else{
            if((sx/n)%2==1) cout<<sx/n+1<<' '<<n-(sx%n-1);
            else cout<<sx/n+1<<' '<<sx%n;
        }
    }


    return 0;
}
