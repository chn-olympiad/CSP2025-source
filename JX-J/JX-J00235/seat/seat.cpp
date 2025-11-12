#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int yz=1;
int x=1;
int y=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i<=n*m;i++){
        cin >> a[i];
    }
    int xf = a[1];
    sort(a+1,a+1+n*m,greater<>());
    int pos = 0;
    for(int i = 1;i<=n*m;i++){
        if(a[i]==xf){
           pos=i;
           break;
        }
    }

    for(int i = 1;i<pos;){
        if(y==1&&yz==-1){
            if(i!=pos){
                x++;
                yz=1;
                i++;
                continue;
            }
            else{
                break;
            }
        }
        if(y==n&&yz==1){
            if(i!=pos){
                x++;
                yz=-1;
                i++;
                continue;
            }
            else{
                break;
            }
        }
        y+=yz;
        i++;
    }
    cout << x<<' '<<y<< '\n';
}
