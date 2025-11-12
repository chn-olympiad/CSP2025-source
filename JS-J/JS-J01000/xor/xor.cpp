#include<bits/stdc++.h>
using namespace std;
int a[500005],b[1048585];
vector<int> v;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int cnt=0,nowxor=0;
    for(int i=1;i<=n;i++){
        b[nowxor]=1;v.push_back(nowxor);
        nowxor^=a[i];
        if(b[nowxor^k]){
            cnt++;
            nowxor=0;
            for(int j=0;j<v.size();j++) b[v[j]]=0;
            v.clear();
        }
    }
    cout<<cnt;
    return 0;
}
