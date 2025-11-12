#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+10;
int a[N];
int n,m;
bool cmp(int a,int b){
    return a>b;
}

signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

cin>>n>>m;//n 行  m  列
for(int i=1;i<=n*m;i++){

        cin>>a[i];

}
int x=a[1];
int root=0;
sort(a+1,a+m*n+1,cmp);
for(int i=1;i<=n*m;i++){
    if(x==a[i]){
        root=i;
        break;
    }
}
int m1=1,n1=1;
for(int i=1;i<=root;i++){
        if(i==root){
            cout<<m1<<" "<<n1;
            return  0;
        }

    if(m1%2!=0){
        if(n1==n){
            m1++;
        }
        else{
            n1++;
        }
    }
    else{
        if(n1==1){
            m1++;
        }
        else{
            n1--;
        }
    }
}

return 0;

}
