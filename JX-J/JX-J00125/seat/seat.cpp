#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=110;
int n,m;
int a[N];
int k=1;
int main(){
    IOS;

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>a[1]){
            k++;
        }
    }
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            k--;
            if(k==0){
                if(j%2==1){
                    cout<<j<<" "<<i;
                }
                else {
                    cout<<j<<" "<<n-i+1;
                }
                return 0;
            }
        }
    }

    return 0;
}

/*
2 2
99 100 97 98


2 2
98 99 100 97


*/













