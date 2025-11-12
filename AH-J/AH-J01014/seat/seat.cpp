#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <queue>
using namespace std;
int n,m,aa;
int a[105];
bool cmp(int a,int b){
    return a>=b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
        cin>>a[i];
    }
    aa=a[1];
    sort(a+1,a+m*n+1,cmp);
    for(int i=1,x=1,y=1;i<=m*n;i++){
        if(a[i]==aa){
            cout<<x<<" "<<y;
            break;
        }
        if(x%2==0){
            if(y==1)   x+=1;
            else    y--;
        }
        else if(x%2==1){
            if(y==n)    x+=1;
            else    y++;
        }
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
