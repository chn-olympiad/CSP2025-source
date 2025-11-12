#include<bits/stdc++.h>
using namespace std;
int c,s,a,ac[100000],acc,b,aac[1000];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>a>>c;
    s=a*c;
    for(int i=1;i<=s;i++){
        cin>>ac[i];
        aac[i]=ac[i];
    }
    sort(aac+1,aac+1+s);
    for(int i=s;i>=1;i--){
        if(aac[i]==ac[1]){
            b=s-i+1;
            break;
        }
    }
    acc=b/a;
    if(b%a==0){
        if(acc%2==0){
            cout<<acc<<" "<<1;
            return 0;
        }
        cout<<acc<<" "<<a;
        return 0;
    }
    acc++;
    if(acc%2==0){
        cout<<acc<<" "<<acc*a-b+1;
        return 0;
    }
    cout<<acc<<" "<<a-(acc*a-b);
    return 0;
}
