#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int sum[N];//yihuo jisuan d qzh
int len[N];
bool ans[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    cin>>a[1];
    sum[1]=a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        bool idx=false;
        for(int j=i;j<=n;j++){
            int t=sum[j]^sum[i-1];
            if(i-1==0){
                t=sum[j];
            }
            if(t==k){
                len[i]=j;
                idx=true;
                break;
            }
        }
        if(idx==false){
            len[i]=-1;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(len[i]<0){
            continue;
        }
        int maxi=i,minl=len[i];
        for(int j=i;j<=minl;j++){
            if(len[j]>=0&&len[j]<=minl){
                maxi=j;
                minl=len[j];
            }
        }
        i=minl;
        ans[minl]=true;
    }
    for(int i=1;i<=n;i++){
        if(ans[i]){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
