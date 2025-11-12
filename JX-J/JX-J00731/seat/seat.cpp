#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL n,m,s[105],x;
bool cmp(long long a,long long b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>x;
    s[1]=x;
    for(int i=2;i<=n*m;i++) cin>>s[i];
    sort(s+1,s+1+(n*m),cmp);
    LL num;
    for(int i=1;i<=n*m;i++){
        if(s[i]==x) num=i;
    }
    LL a,b;
    a=num/n+(num%n>0);
    cout<<a<<' ';
    if(a%2){
        LL num1=num%n;
        if(num1==0) num1=n;
        cout<<num1;
    }else{
         LL num1=num%n;
         if(num1==0) num1=n;
         cout<<n+1-num1;
    }
    return 0;
}

