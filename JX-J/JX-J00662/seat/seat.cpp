#include<bits/stdc++.h>
using namespace std;
int a[110];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int x=a[1];
    sort(a+1,a+n*m+1);
    int c=n*m;


    for(int i=1;i<=m;i++){
        if(i%2==1){
        for(int j=1;j<=n;j++){
            int k=a[c];
            if(k==x){
                cout<<i<<" "<<j;
                return 0;
            }
            c--;
        }
        }
        else{
            for(int j=n;j>=1;j--){
            int k=a[c];
            if(k==x){
                cout<<i<<" "<<j;
                return 0;
            }
            c--;
        }
        }
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
