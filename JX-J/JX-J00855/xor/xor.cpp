#include<iostream>
#include<algorithm>
using namespace std;
int a[500005];
long long s[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i]=(s[i-1]^a[i]);
    }
    int minn=1;
    long long cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=minn;j<=i;j++){
            if((s[i]^s[j-1])==k){
                cnt++;
                minn=i+1;
                break;
            }

        }
    }
    cout<<cnt;
    return 0;
}
