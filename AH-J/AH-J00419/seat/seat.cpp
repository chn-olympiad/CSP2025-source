#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[105],st,x,y;
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
    st=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==st){
            x=i/n;
            y=i%n;
            break;
        }
    }
    x++;
    if(y==0){
        x--;
        y=n;
    }
    if(x%2==0) y=n-(y-1);
    cout<<x<<" "<<y;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
