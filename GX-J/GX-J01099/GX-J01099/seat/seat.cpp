#include<iostream>
#include<algorithm>

using namespace std;

int n,m;
int a[110];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];

    int ans=a[1];

    sort(a+1,a+1+n*m);

    int x=1,y=1,l=n*m;
    bool z=1;

    while(a[l]!=ans){
        if(z==1&&x+1<=n){
            x++;
        }
        else if(z==0&&x-1>=1){
            x--;
        }
        else if(z==1&&x<=n){
            y++;
            z=0;
        }
        else if(z==0&&x>=1){
            y++;
            z=1;
        }
        l--;
    }

    printf("%d %d",y,x);

    return 0;
}
