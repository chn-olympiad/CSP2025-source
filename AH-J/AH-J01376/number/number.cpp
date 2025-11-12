#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long long s;
    cin>>s;
    int a[1000000],x=0;
    do{
        a[x]=s%10,s/=10,x++;
    }while(s!=0);
    sort(a,a+x);
    if(x==1)cout<<s;
    else{
        for(int i=x-1;i>=0;i--)
            cout<<a[i];
    }
    return 0;
}
