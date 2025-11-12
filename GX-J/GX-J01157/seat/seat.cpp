#include<bits/stdc++.h>
using namespace std;
long long s[10086];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long a,b,sum=1;
    cin>>a>>b;
    for(int i=1;i<=a*b;i++){
        cin>>s[i];
        if(s[1]<s[i])
            sum++;
    }
    if(sum==a){
        cout<<sum/a<<' '<<a;
        return 0;
    }
    else if(sum%a==1){
        cout<<sum/a+1<<' '<<1;
        return 0;
    }
    cout<<sum/a+1<<' '<<a-sum%a+1;
    return 0;
}
