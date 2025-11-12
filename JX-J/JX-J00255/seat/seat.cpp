#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int a[210];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int cnt=a[1];
    int now;
    sort(a+1,a+(n*m+1),cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==cnt){
            now=i;
            break;
        }
    }
    int c=1,r=1;
    int v=0;
    for(int i=1;i<=now;){
        if(a[i]==cnt){
            cout<<c<<" "<<r;
            return 0;
        }
        for(int j=1;j<n;j++){
            i++;
            r++;
            if(a[i]==cnt){
                cout<<c<<" "<<r;
                return 0;
            }
        }
        c++;
        i++;
        if(a[i]==cnt){
            cout<<c<<" "<<r;
            return 0;
        }
        for(int j=1;j<n;j++){
            i++;
            r--;
            if(a[i]==cnt){
                cout<<c<<" "<<r;
                return 0;
            }
        }
        i++;
        c++;
        if(a[i]==cnt){
            cout<<c<<" "<<r;
            return 0;
        }
    }
    return 0;
}
