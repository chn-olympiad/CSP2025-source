#include<bits/stdc++.h>
using namespace std;
int n,m,a,b;
int r=1,c=1,ans=1;
int s[150];
int main(){
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    cin>>n>>m;
    a=n*m;
    for(int i=1;i<=a;i++){
        cin>>s[i];
        b=s[1];
        if(b<s[i]&&ans%2!=0){
            r++;
        }else if(b<s[i]&&ans%2==0){
            r--;
        }
        if(r>n){
            ans++;
            if(ans%2==0){
                r=n;
                c++;
            }
        }
        if(r<1){
            r=1;
            ans++;
            c++;
        }

    }
    cout<<c<<" "<<r;
    return 0;
}
