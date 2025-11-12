#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
const int N=1e5+5;
int n,m,x=1,y=1,f=0,cnt,xx,yy,cnt1=1;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    cnt=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    if(a[1]==cnt){
        cout<<"1 1";
        return 0;
    }
    int k=n*m-1;
    while(k--){
        if(f==0&&x==n){
            f=1;
            y++;
            x++;
        }else if(f==1&&x==1){
            f=0;
            y++;
            x--;
        }
        cnt1++;
        if(f==0)x++;
        if(f==1)x--;
        if(a[cnt1]==cnt){
            cout<<y<<' '<<x;
            return 0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}