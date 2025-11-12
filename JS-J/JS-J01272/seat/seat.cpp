#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int n,m;
int a[105];

bool cmp(int x,int y){
    return x>y;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;++i){
        cin>>a[i];
    }
    int R=a[0];
    sort(a,a+n*m,cmp);
    for(int c=1;c<=m;++c){
        if(c%2){
            for(int r=1;r<=n;++r){
                if(a[(c-1)*n+r-1]==R){
                    cout<<c<<" "<<r<<endl;
                    return 0;
                }
            }
        }else{
            for(int r=n;r>=1;--r){
                if(a[(c-1)*n+(n+1-r)-1]==R){
                    cout<<c<<" "<<r<<endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}