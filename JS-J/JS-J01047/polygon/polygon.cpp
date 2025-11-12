#include<bits/stdc++.h>
using namespace std;
//wu ri n xing wu shen:
//define int long long & signed main hu?
//freopen shan zhu shi hu?
//da yang li ce shi le hu?
//bian liang chu shi hua le hu?
//han shu xie fan hui zhi le hu?
//shu zu da xiao he shi hu?
//bu yong zi mu+shu zi / wan zheng dan ci zuo bian liang ming hu?
//bian yi tong guo le hu?
//jian cha shu chu shi kong ge hai shi huan hang le hu?
#define int long long
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int cnt=0;
    int a[n+2];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int st=0;st<(1<<n);st++){
        vector<int> v;
        for(int i=0;i<n;i++)if(st&(1<<i))v.push_back(a[i]);
        int sumx=0,maxx=0;
        for(int i:v)sumx+=i,maxx=max(maxx,i);
        if(sumx>2*maxx)cnt++,cnt=(cnt+998244353)%998244353;
    }
    cout<<(cnt+998244353)%998244353;
    return 0;
}
