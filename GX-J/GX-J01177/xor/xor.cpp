#include <iostream>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","r",stdout);
    int n,a[100],num=0,maxn=0;
    cin>>n;
    while(n>0){
        a[num]=n%2;
        n=n/2;
        num++;
    }
    for(int i=num-1;i<=0;i--){
        if(i>maxn){
            maxn=i;
        }
    }
    cout<<maxn;
    return 0;
}
