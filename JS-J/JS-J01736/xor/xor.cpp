#include<cstring>
#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    freopen("xor6.in","r",stdin);
    freopen("xor6.out","w",stdout);
    ios::sync_with_stdio(false);
    int n,k,a[500000],pre[500001]={0},lst[1048576];
    memset(lst,-1,sizeof lst);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        pre[i+1]=pre[i]^a[i];
    }
    int idx=0,ans=0;
    for(int i=0;i<n;i++){
        lst[pre[i]]=i;
        if(lst[pre[i+1]^k]>=idx){
            ans++,idx=i+1;
        }
    }
    cout<<ans;
    return 0;
}
