#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1100];
bool cmp(int x,int y){
    return x>y;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int k;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1)k=a[i];
    }
    sort(a+1,a+1+n*m,cmp);
    int x=0,y=1,l=0,c=0;
    for(int i=1;i<=n*m;i++){
        c++;
        if(l==0){
            if(x+1>n){
                l=1;
                y++;
                if(a[c]==k){
                    cout<<y<<" "<<x;
                    break;
                }
                continue;
            }
            x++;
            if(a[c]==k){
                cout<<y<<" "<<x;
                break;
            }

        }else{
            if(x-1<1){
                l=0;
                y++;
                if(a[c]==k){
                    cout<<y<<" "<<x;
                    break;
                }
                continue;
            }
            x--;
            if(a[c]==k){
                cout<<y<<" "<<x;
                break;
            }

        }


    }

    return 0;
}
