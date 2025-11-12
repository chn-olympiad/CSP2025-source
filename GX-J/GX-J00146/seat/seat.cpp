#include<bits/stdc++.h>
using namespace std;
int a[11][11]={0},n,m,f=0,l=0;
int sotr[121];
void daying(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int k=n*m;
    for(int i=1;i<=k;i++){
        cin>>sotr[i];
        if(i==1) f=sotr[i];
    }
    sort(sotr+1,sotr+k+1);
    reverse(sotr+1,sotr+k+1);

    if(n==1){
        for(int i=1;i<=k;i++){
            if(sotr[i]==f){
                cout<<i<<" "<<1;
            }
        }
    }
    else if(m==1){
        for(int i=1;i<=k;i++){
            if(sotr[i]==f){
                cout<<1<<" "<<i;
            }
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
