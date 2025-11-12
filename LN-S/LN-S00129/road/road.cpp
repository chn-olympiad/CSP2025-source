#include<bits/stdc++.h>
using namespace std;
struct dian{
    int q,w,e;
};dian op[100000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    long long a,s,d,ans=0;
    scanf("%lld%lld%lld",&a,&s,&d);
    for(int i=0;i<s;i++){
        scanf("%d%d%d",&op[i].q,&op[i].w,&op[i].e);
        ans+=op[i].e;
    }
    cout<<ans;
    return 0;
}
