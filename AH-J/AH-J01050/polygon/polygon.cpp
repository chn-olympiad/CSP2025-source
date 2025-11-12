#include<bits/stdc++.h>
using namespace std;
long long a[2100000],n,cnt=0,zd,tp=1;
map <long long,long long> mp;
long long qy=998244353;
long long cjj(long long x,long long y){
    long long sm=1,xm=1;
    for(int i=1;i<=x;i++){
        sm*=(y-i+1);
        xm*=i;
        xm%=qy;
        sm%=qy;
    }
    return sm/xm;

}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
    if(a[i]!=1){
        tp=0;
    }
}
if(tp==1){
    int k=0;
    for(int i=3;i<=n;i++){
        k+=cjj(i,n);
    }
    cout<<k<<endl;
    return 0;
}
sort(a+1,a+1+n);
for(int i=1;i<=n;i++){

    for(int j=zd;j>=a[i]+1;j--){
        if(mp[j]>0){
            mp[j+a[i]]+=mp[j];
            cnt+=mp[j];
            mp[j+a[i]]%=998244353;
            cnt%=998244353;
        }
    }
    for(int j=a[i];j>=1;j--){
        if(mp[j]>0){
            mp[j+a[i]]+=mp[j];
            mp[j+a[i]]%=998244353;
        }
    }
    mp[a[i]]++;
    zd+=a[i];
}
cout<<cnt%998244353;
    return 0;
}
/*
sb ccf chu de shen mo ti mu
我这T3写法 与其说是dp，不如叫暴力dp
                ^^
                md zhe dp yong zhe ge shu ru fa zhang de gen "do" yi yang
666 我手上的电解质是9月1日产的
tmd bu lai hui qie huan shu ru fa le
qie huan shu ru fa de an nui zai guan ji jian pang bian
deng hui dian dao guan ji jian jiu lao shi le
to be honest i really think that ccf is so bad
bao ming fei zen mo zhe mo gui
oh dui le qu nian chu sai shi juan xie lou de shi chu li de zn mo yang le
dou kuai wang le ,deng hui wo qu kan kan
yu ce fen shu:
T1 100 T2 100 T3 55 T4 55
yin gai neng na 2 deng
best wishes
shi zhe yang pin de ma

cai le gou shi yun shi bu shi na ge ren cai jiang lucky dog fan yi er lai de

hai you 7 min jiu jiao juan le
zui hou zai shuo ji ju ba
mang shang jiu yao zhong kao le
xue le zhe mo jiu j2 dou bu neng AK
s1 dou mei guo
ai xie xu wo jiu shi fvv ba
yi zhong de feng jing hen mei dan wo ye kao bu shang le
xie zhe xie hua gei shui kan ne
gei ni he wei lai de wo ba
bey
*/
