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
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int a[n+2];
    for(int i=0;i<n;i++)cin>>a[i];
    unordered_map<int,int> mp;
    int xorr[n+2];
    xorr[0]=a[0];
    mp[xorr[0]]++;
    for(int i=1;i<n;i++)xorr[i]=xorr[i-1]^a[i],mp[xorr[i]]++;
    int l=0,r=0,num=0,cnt=0;
    while(l>=0&&l<n&&r>=0&&r<n&&l<=r){
        num^=a[r];
        if(k==num){
            //cout<<l<<" "<<r<<endl;
            cnt++,l=r+1,r=l,num=0;
        }
        else{
            if(mp[k^num^xorr[r]]!=0)r++;
            else l++,r=l,num=0;
        }
    }
    cout<<cnt;
    return 0;

}
