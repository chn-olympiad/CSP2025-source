#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    if(a>b) return true;
    else return false;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m+1];
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int p=a[1];
    int x=0,y=0;
    sort(a+1,a+n*m+1,cmp);
    int id=0;
    for(int i=1;i<=n*m;i++){
        if(a[i]==p) id=i;
    }
    y=floor(id/m)+1;
    if(y%2==1){
        x=m-(id%n+1);
    }else{
        x=id%n+1;
    }
    cout<<y<<" "<<x<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
