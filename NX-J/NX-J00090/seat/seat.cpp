#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m];
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int sum=a[0];
    sort(a,a+n*m);
    if(a[0]==sum){
        cout<<n<<" "<<m;
    }
    else if(a[n*m-1]==sum){
        cout<<1<<" "<<1;
    }
    else{
        cout<<n-n/m<<" "<<m;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
