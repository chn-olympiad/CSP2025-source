#include<bits/stdc++.h>

using namespace std;
int xord(int x,int y)
{
    return x^y;
}
int xx[200005],yy[200005];
long long suf[200005];
int a[200005];
int main(){
    //freopen("xor.in","r",stdin);
    //freopen("xor.out","w",stdout);
    int n,k,cnt=0,sum=1;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j>0;j--){
            cnt=xord(a[j],cnt);
            if(cnt==k){
                cout<<i<<' '<<j<<endl;
                xx[sum]=i;
                yy[sum]=j;
                sum++;
                suf[i]++;
                suf[j+1]--;
                break;
            }
        }
    }
    suf[0]=0;
    for(int i=1;i<=n;i++){
        suf[i]+=suf[i-1];
    }
    sum--;
    for(int i=1;i<=n;i++){
        cout<<suf[i]<<' ';
    }
    return 0;
}
