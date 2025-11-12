#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int tmp[150];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    cin>>tmp[0];
    int a1=tmp[0];
    for(int i=1;i<n*m;i++){
        cin>>tmp[i];
    }
    sort(tmp,tmp+n*m,greater<int>());
    for(int i=0;i<n*m;i++){
        if(tmp[i]==a1){
            a1=i;
            break;
        }
    }
    a1++;
    int lsl=0;
    if(a1%n==0){
        cout<<a1/n<<" ";
        lsl=a1/n;
    }else {
        cout<<a1/n+1<<" ";
        lsl=a1/n+1;
    }
    if(a1%n==0){
        cout<<n<<endl;
    }else if(lsl%2==0){
        cout<<n-a1%n+1<<endl;
    }else {
        cout<<a1%n<<endl;
    }
    return 0;
}