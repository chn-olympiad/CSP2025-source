#include <iostream>
using namespace std;
const int N = 500005;
int shu[N];
bool flag[N]={false};
int main(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
    int n,k,ans=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>shu[i];
        if(shu[i]==k){
            ans++;
            flag[i]=true;
        }
    }
    if(n==1){
        cout<<ans;
        return 0;
    }
    for(int i=0;i<n;i++){
        if(flag[i]==true){
            continue;
        }
        for(int j=i,tmp=0;j<n;j++){
            if(flag[j]==true){
                break;
            }
            tmp=tmp^shu[j];
            flag[j]=true;
            if(tmp==k){
                ans++;
                i=j+1;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}