#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct sj{
    ll sl;
    int wei;
    sj(ll sl1,int wei1){
       sl=sl1;
       wei=wei1;
    }
};
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,q;
    scanf("%d",&n);
    vector<int>length;
    for(int i=0;i<n;i++){
        scanf("%d",&q);
        length.push_back(q);
    }
    sort(length.begin(),length.end());
    int count_long=0;
    vector<sj>yx;
    for(int i=2;i<length.size();i++){
        for(int o=1;o<i;o++){
            for(int p=0;p<o;p++){
                if(length[i]*2<length[i]+length[o]+length[p]){
                    count_long++;
                }
                yx.push_back(sj(length[i]+length[o]+length[p],i));
            }
        }
    }
    int p=0,endshu=0,beginshu=0;
    for(int i=3;i<length.size();i++){
        beginshu=endshu;
        endshu=yx.size();
        for(int o=i;o<length.size();o++){
            p=beginshu;
            for(;yx[p].wei<o;p++){
                if(yx[p].sl+length[o]>length[o]*2){
                    count_long++;
                }
                yx.push_back(sj(yx[p].sl+length[o],o));
            }
        }

    }
    cout<<count_long;
    return 0;
}
