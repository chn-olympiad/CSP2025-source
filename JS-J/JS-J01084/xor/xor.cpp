#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+7;
ll n,k;
int l[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int a=0,b=0;
    for(int i=1;i<=n;i++){
        cin>>l[i];
        if(l[i]==0)a++;
        else if(l[i]==1)b++;
    }
    if(a+b==n){
        if(a>0){
            if(k==0){
                cout<<a+b/2<<endl;
                return 0;
            }
            else{
                cout<<b<<endl;
                return 0;
            }
        }
        else{
            cout<<b/2<<endl;
            return 0;
        }
    }
    return 0;
}
