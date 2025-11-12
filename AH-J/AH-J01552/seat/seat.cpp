#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
int a[105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int c=a[1];
    sort(a+1,a+n*m+1,cmp);
    /*
    for(int i=1;i<=n*m;i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
    */
    for(int i=1;i<=n*m;i++){
        if(a[i]==c){
            c=i;
            break;
        }
    }

    if(c%m==0){
        x=c/m;
        if(x%2==1){
            y=n;
        }else{
            y=1;
        }
    }else{
        x=c/m+1;
        if(x%2==1){
            y=c%m;
        }else{
            y=n-c%m+1;
        }
    }
    cout<<x<<' '<<y;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
