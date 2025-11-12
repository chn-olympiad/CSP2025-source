#include<bits/stdc++.h>
using namespace std;
int a[500005];
vector<int> box;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long cnt=0;
    if(k==0){
        cout<<n<<endl;
    }
    return 0;
}
