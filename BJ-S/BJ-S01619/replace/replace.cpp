#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    vector<pair<string,string>> rp(n+1);
    for(int i=1;i<=n;i++)cin>>rp[i].first>>rp[i].second;
while(q--){
    int sum=0;
    string s1,s2;
    cin>>s1>>s2;
    for(int i=1;i<=n;i++){
        size_t pos1=s1.find(rp[i].first);
        if(pos1!=string::npos){
            string s3=s1;
            for(int j=0;j<rp[i].first.size();j++)s3[pos1+j]=rp[i].second[j];
            if(s3==s2)sum++;
        }
    }
    cout<<sum<<'\n';
}
    return 0;
}
