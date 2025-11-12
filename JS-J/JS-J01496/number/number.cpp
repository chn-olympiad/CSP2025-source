#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int b[N],c;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a,n=0,sum=0;
    cin>>a;
    while(a!=0){
        n++;
        b[n]=a%10;
        a=a/10;
    }
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++){
        if(i==1){
            sum=sum+b[i];
        }
        else{
            for(int j=i;j>1;j--) b[i]=b[i]*10;
            sum+=b[i];
        }
    }
    cout<<sum;
    return 0;
}
