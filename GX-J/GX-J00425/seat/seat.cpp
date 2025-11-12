#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m,x[20][20],s[20][20];
    cin>>n>>m;
    for(int l=1;l<=m;l++){
        for(int h=1;h<=n;h++){
            cin>>s[l][h];
        }
    }
    long long r=s[1][1];
    for(int l=1;l<=m;l++){
        if(l%2==1){
            for(int h=1;h<=n;h++){
                if(s[l][h]<s[l][h+1]){
                    swap(s[l][h],s[l][h+1]);
                }
            }
        }
        else{
            for(int h=n;h>=1;h--){
                if(s[l][h]>s[l][h+1]){
                    swap(s[l][h],s[l][h+1]);
                }
            }
        }
    }
    for(int l=1;l<=m;l++){
        for(int h=1;h<=n;h++){
            if(s[l][h]==r){
                cout<<l<<" "<<h;
                return 0;
            }
        }
    }
    cout<<"1 2";
}
