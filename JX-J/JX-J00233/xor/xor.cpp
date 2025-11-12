#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,k,a[N],x,cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        if((x^a[i])==k) cnt++,x=0;
        else x^=a[i];
    }
    cout<<cnt;
    return 0;
}
