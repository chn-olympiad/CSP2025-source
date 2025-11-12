#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int a[110];
int main(){
    freopen("seat,in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int t=n*m;
    for(int i=1;i<=t;i++)
        cin>>a[i];
    int r=a[1];
    sort(a+1,a+t+1);
    int pos;
    for(int i=t;i>=1;i--){
        if(a[i]==r){
            pos=t-i+1;
            break;
        }
    }
    int x,y;
    y=(pos/n)+1;
    x=pos%n;
    if(y%2==0)x=n+1-x;
    cout<<y<<' '<<x;
    fclose(stdin);
    fclose(stdout);
    return 0;
}