#include<bits/stdc++.h>
using namespace std;
int a[105];
bool ch(int x,int y){
return x>y;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int s=a[1];
    sort(a+1,a+n*m+1,ch);
    for(int i=1;i<=n*m;i++){
        if(s==a[i])s=i;
    }
    for(int i=1;i<=m;i++){
        if(s<=n){
            cout<<"1"<<" "<<s;
            return 0;
        }
        if(s<=n*i&&i%2==0){
            s=s-(i-1)*n-1;
            cout<<i<<" "<<n-s;
            return 0;
        }
        if(s<=n*i&&i%2!=0){
            cout<<i<<" "<<s-(i-1)*n;
            return 0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
