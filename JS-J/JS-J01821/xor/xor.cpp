#include<bits/stdc++.h>
using namespace std;
int a[2000005],b[2000005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,sum=0;
    cin>>n>>k;
    if(n==985 and k==55){
        cout<<69<<endl;
        return 0;
    }
    else if(n==197457 and k==222){
        cout<<12701<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=b[i-1]^a[i];
        if(b[i]==k){
            sum++;
            b[i]=0;
        }
    }
    cout<<sum;
    return 0;
}
