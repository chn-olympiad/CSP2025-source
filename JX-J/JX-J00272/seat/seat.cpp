#include <bits/stdc++.h>
#define LL long long
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"
using namespace std;
const int N=10e6+10;
bool cmp(int a,int b){
    return a>b;
}
int n,m;//hang,lie
int r,c;//hang,lie
int a[N],b;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    IOS;
    cin>>n>>m;
    int g=n*m;
    for(int i=0;i<g;i++){
        cin>>a[i];
    }
    int x=a[0];
    sort(a,a+g,cmp);
    for(int i=0;i<g;i++){
        if(a[i]==x){
            b=i+1;
            break;
        }
    }
    if(b>n){
        if(b%n==0){
            if((b/n)%2==0){
                r=1;
                c=b/n;
                cout<<c<<" "<<r;
                return 0;
            }else{
                r=n;
                c=b/n;
                cout<<c<<" "<<r;
                return 0;
            }
        }else{
            if((b/n)%2==0 && b%n==0){
                c=b/n+1;
                r=n-b%n+1;
                cout<<c<<" "<<r;
                return 0;
            }else{
                c=b/n+1;
                r=b%n;
                cout<<c<<" "<<r;
                return 0;
            }
        }
    }else if(b==n){
        cout<<"1"<<" "<<n;
        return 0;
    }else{
        cout<<"1"<<" "<<b;
        return 0;
    }




    return 0;
}

