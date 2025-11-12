#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int p=a[1];
    int o=0;
    sort(a+1,a+n*m+1);
    reverse(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==p){
            o=i;
        }
    }
    int k=o%n;
    if(k==0){
        cout<<o/n<<" ";
        if((o/n)%2==0){
            cout<<1;
        }else{
            cout<<n;
        }
    }
    else{
        o-=k;
        int f=o/n;
        if(f%2==0){
            cout<<f+1<<" "<<k;
        }
        else{
            cout<<f+1<<" "<<n+1-k;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
