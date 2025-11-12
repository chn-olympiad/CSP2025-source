#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[105];
bool cmp(int x,int y){
return x>y;}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x;
    cin >> n >> m;
    for(int i=1;i<=n*m;i++){
        cin >> a[i];
        if(i==1){
            x=a[i];
        }
    }
    sort(a+1,a+n*m+1,cmp);
    int c,r;
    for(int i=1;i<=n*m;i++){
        if(a[i]==x){
            c=(i+n-1)/n;
            if(c%2==0){
                if(i%n==0)
                    r=1;
                else{
                    r=n-i%n;
                }
            }
            else{
                if(i%n==0)
                    r=n;
                else{
                    r=i%n;
                }
            }
            cout << c<<" "<< r;
            break;
        }
    }
    return 0;
}
