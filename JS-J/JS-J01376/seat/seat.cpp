#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int res=a[1];
    sort(a+1,a+1+n*m);
    reverse(a+1,a+1+n*m);
    int id=0;
    for(int i=1;i<=n*m;i++){
        if(a[i]==res){
            id=i;
            break;
        }
    }
    int x=1,y=1;
    int fx=1;
    int k=1;
    while(k<=id){
        if(k==id){
            cout<<y<<" "<<x<<"\n";
            return 0;
        }
        if(x==n&&fx==1) y++,fx=2;
        else if(x==1&&fx==2) y++,fx=1;
        else{
            if(fx==2) x--;
            else x++; 
        } 
        k++;
    }
    return 0;
}