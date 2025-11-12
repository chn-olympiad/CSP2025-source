#include<iostream>
#include<string>
using namespace std;
const int size=2e5+8;
string rule[size][2],q1,q2;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>rule[i][0]>>rule[i][1];
    }
    for(int i=0;i<q;i++){
        cin>>q1>>q2;
        int ans=0;
        for(int j=0;j<n;j++){
            q1.find(rule[j][0]);
            try{
                if(q2==q1.substr(0,q1.find(rule[j][0]))+rule[j][1]+q1.substr(q1.find(rule[j][0])+rule[j][0].size()))ans++;
            }
            catch(out_of_range){
                continue;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}//Until 18:45
//Then I can see my parents,my friends...