#include <bits/stdc++.h>
using namespace std;
int n,m,x;
int b[100005];
int a[100][100];
void gj(int x){
    int i=1,j=1;
    int f=0,s=1;
    while(s!=n*m+1){
        a[i][j]=s;
        if(s==x){
            cout<<j<<" "<<i;
        }
        s++;
        if(f==0){
            i++;
            if(i>n){
                i--;
                j++;
                f=1;
            }
        }
        else if(f==1){
            i--;
            if(i<1){
                i++;
                j++;
                f=0;
            }
        }
        
    }
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen ("seat.in","r",stdin);
    freopen ("seat.out","w",stdout);
    cin>>n>>m;
    
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    x=b[1];
    sort(b+1,b+(n*m)+1);
    reverse(b+1,b+(n*m)+1);
    for(int i=1;i<=n*m;i++){
        if(b[i]==x){
            gj(i);
            break;
        }
    }
    
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<setw(3)<<a[i][j];
    //     }
    //     cout<<'\n';
    // }
    return 0;
}