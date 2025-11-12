#include<iostream>
#include<vector>
#include<algorithm>
#define i64 long long
#define ui unsigned int
using namespace std;
struct member{i64 d1,d2,d3,d;}s;
vector<member> B[3];
i64 n,ma,ans;
short t;
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin>>t;while(t--){
            cin>>n;for(ui i=1;i<=n;i++){
            cin>>s.d1>>s.d2>>s.d3;
            ma=max(s.d1,max(s.d2,s.d3));
            if(ma==s.d1){
                B[0].push_back(s);
                ans+=s.d1;
                continue;
            }
            if(ma==s.d2){
                B[1].push_back(s);
                ans+=s.d2;
                continue;
            }
            if(ma==s.d3){
                B[2].push_back(s);
                ans+=s.d3;
                continue;
            }
        }
        ui l1=B[0].size(),l2=B[1].size(),l3=B[2].size();
        if(l1>(n>>1)){
            for(ui i=0;i<l1;i++) B[0][i].d=max(B[0][i].d2,B[0][i].d3)-B[0][i].d1;
            sort(B[0].begin(),B[0].end(),[](member a,member b){return a.d>b.d;});
            for(ui i=0;i<l1-(n>>1);i++) ans+=B[0][i].d;
        }
        if(l2>(n>>1)){
            for(ui i=0;i<l2;i++) B[1][i].d=max(B[1][i].d1,B[1][i].d3)-B[1][i].d2;
            sort(B[1].begin(),B[1].end(),[](member a,member b){return a.d>b.d;});
            for(ui i=0;i<l2-(n>>1);i++) ans+=B[1][i].d;
        }
        if(l3>(n>>1)){
            for(ui i=0;i<l3;i++) B[2][i].d=max(B[2][i].d2,B[2][i].d1)-B[2][i].d3;
            sort(B[2].begin(),B[2].end(),[](member a,member b){return a.d>b.d;});
            for(ui i=0;i<l3-(n>>1);i++) ans+=B[2][i].d;
        }
        cout<<ans<<"\n";
        B[0].clear(),B[1].clear(),B[2].clear();ans=0;
    }
}
