#include<bit/stdc++.h>
using namespace std;
const int N = 10010;
int n,m,a[N][N],c,r,b[N],num;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 0;i<n*m;i++)cin >> b[i];
    int x = b[0];
    for(int i = 0;i<n*m;i++){
        if(a[i]>x)num++;
    }
    for(int i = 0;i<n;i++){
            if(num>i)j+=1,i=0;
            c=j,r=i;
    }
     cout << c << r;
     return 0;
}
