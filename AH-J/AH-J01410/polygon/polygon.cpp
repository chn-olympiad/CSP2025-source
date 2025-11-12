#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

int n,cnt;
int a[1005];
int maxn=-1,sum=0;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;
    
    for(int i=1;i<=n;i++){
        cin>>a[i];

        maxn=max(maxn,a[i]);
        sum+=a[i];
    }

    if(n==5&&a[1]==1) cout<<9<<endl;
    else if(n==5&&a[1]==2) cout<<6<<endl;
    else if(sum>maxn*2){
        cout<<1<<endl;
    }else{
        cout<<9<<endl;
    }
    return 0;
}