#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+11;
int a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int maxn=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int cnt=j,num=a[cnt],tot=0;
            while(cnt<=n){
                while(num==k) tot++,num=a[++cnt];
                num=num^a[++cnt];
            }
            maxn=max(maxn,tot);
        }
    }
    cout<<maxn<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//for

//dp
