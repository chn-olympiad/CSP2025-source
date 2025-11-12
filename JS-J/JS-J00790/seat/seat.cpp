#include <bits/stdc++.h>
using namespace std;

void read(int &x){
    x=0;int f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<3)+(x<<1)+ch-'0';
        ch=getchar();
    }
    x*=f;
}
const int N=1e5+10;
int n,m;
struct student{
    int id,sc;
}a[N];
int mp[100][100];
bool cmp(student x,student y){
    return x.sc>y.sc;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    read(n),read(m);
    for(int i=1;i<=n*m;i++){
        read(a[i].sc);
        a[i].id=i;
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        int col=i/n+1,row;
        if(i%n==0) col=i/n;
        if(col&1){
            row=(i-1)%n+1;
        }
        else {
            row=n-((i-1)%n+1)+1;
        }
        mp[row][col]=a[i].id;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]==1){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }

    return 0;
}
