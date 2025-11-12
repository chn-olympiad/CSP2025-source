#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],b;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    b=a[0];
    sort(a,a+n*m);
    for(int i=0;i<n*m;i++){
        if(b==a[i]){
            cout<<m-i/n<<" ";
            if((m-i/n)%2==0)cout<<m-((m*n-i-1)%m);
            else cout<<((m*n-i-1)%m)+1;
            break;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
