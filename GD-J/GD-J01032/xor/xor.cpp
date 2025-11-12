#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k;
int a[N];
int A,B;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    A=B=1;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0)
            A=0;
        if(a[i]>1)
            A=B=0;
        sum+=a[i];
    }
    if(A){
        if(k==1)
            cout<<n<<endl;
        else if(k==0)
            cout<<n/2<<endl;
        else
            cout<<0<<endl;
    }else if(B){
        if(k==1)
            cout<<sum<<endl;
        else{
            int ans=0;
            for(int i=1;i<=n;i++)
                if(i!=1&&a[i]==1&&a[i-1]==1)
                    ans++;
                else if(a[i]==0)
                    ans++;
            cout<<ans<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}