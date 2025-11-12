#include<bits/stdc++.h>
using namespace std;
const long long mod= 998244353;
map<int,array<long long,2>>m;//sum:[already been ready,should add one more]
vector<int>num;
bool cmp(const pair<int,array<long long,2>>&a,const int &b){
    return a.first<b;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    scanf("%d",&n);
    long long solution=0;
    int _sum=0;
    num.resize(n);
    for(auto&i:num){
        scanf("%d",&i);
        _sum+=i;
    }
    sort(num.begin(),num.end());
    int max_num=num.back();
    //m.resize(max_num);
    m[num[0]][1]++;
    for(int i=1;i<n;i++){
        if(m.size()){
            auto it =lower_bound(m.begin(),m.end(),num[i],cmp);
            while((*it).first==num[i]&&it!=m.end())it++;
            while(it!=m.end()){
                solution=(solution+(*it).second[0])%mod;
            it++;
        }
        }

        if(m.size()){
            auto j=m.end();j--;
            while(j!=m.begin()){

                if(num[i]+(*j).first<=_sum){
                    m[num[i]+(*j).first][0]+=((*j).second[1]+(*j).second[0])%mod;
                }
                j--;
            }
            if(num[i]+(*j).first<=_sum){
                 m[num[i]+(*j).first][0]+=((*j).second[1]+(*j).second[0])%mod;
            }
            j--;
        }
        m[num[i]][1]=(m[num[i]][1]+1)%mod;

    }
    printf("%lld",solution%mod);
    fclose(stdin);fclose(stdout);
}