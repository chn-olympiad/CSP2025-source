#include<bits/stdc++.h>
using namespace std;

bool cmp(int x,int y){
    return x>y;
}

int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
    int m,n;
    int a[1000000000];
    int r,c;
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
        cin>>a[i];
    }
    int s=a[1];
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=m*n;i++){
        if(a[i]==s){
            c=a[i]/n+1;
            if(c%2!=0){
                r=a[i]%n;
            }else{
                r=n+1-a[i]%n;
            }
        }
    }
    cout<<c<<r<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
