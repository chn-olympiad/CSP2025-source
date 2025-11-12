#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN(105);
int n,m;
int a[MAXN];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int sum=a[1];
    int weizhi;
    sort(a+1,a+n*m+1,greater<int>());
    for(int i=1;i<=n*m;i++)
        if(a[i]==sum){
            weizhi=i;
            break;
        }
    bool xiawan=false,shangwan=true;
    int x(1),y(0);
    for(int i=1;i<=n*m;i++){
       if(xiawan){
            if(y==1){
                x++;
                shangwan=true;
                xiawan=false;
            }else{
                y--;
            }
       }else if(shangwan){
            if(y==n){
                x++;
                shangwan=false;
                xiawan=true;
            }else{
                y++;
            }
       }
       if(weizhi==i){
            cout<<x<<' '<<y;
            break;
       }
    }
    return 0;
}
