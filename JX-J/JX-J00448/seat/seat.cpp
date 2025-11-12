#include<bits/stdc++.h>
using namespace std;
int n,m;
struct people{
    int num;
    int fs;
}a[105];
bool cmp(people a,people b){
    return a.fs>b.fs;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].fs;
        a[i].num=i;
    }
    sort(a+1,a+n*m+1,cmp);
    int x=0,y=1,k=0;
    for(int i=1;i<=n*m;i++){
        if(k==0){
            x++;
            if(x>n){
                x=n;
                y++;
                k=1;
            }
        }
        else if(k==1){
            x--;
            if(x<1){
                x=1;
                y++;
            }
        }
        
        if(a[i].num==1){
            cout<<y<<" "<<x;
            return 0;
        }
    }
    return 0;
}
