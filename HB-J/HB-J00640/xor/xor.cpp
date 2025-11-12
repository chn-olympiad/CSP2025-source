#include <iostream>
#include <vector>
#include <utility>
using namespace std;
const int MAXN=5e5+1;
int n,k,num[MAXN],ans,trash; vector<pair<int,int>>dist; 
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> num[i];
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++){
            int XOR=num[i];
            for(auto dis:dist) 
                if((i>=dis.first && i<=dis.second) || (j>=dis.first && j<=dis.second)) 
                    goto a;       //避免交叉区间
            for(int z=i+1;z<=j;z++) XOR^=num[z];
            if(XOR==k){
                ans++;
                dist.push_back({i,j}); //如果满足k就给答案+1并且记录
            } 
            a: trash=0;
        }
    cout << ans << '\n';
    return 0;
}