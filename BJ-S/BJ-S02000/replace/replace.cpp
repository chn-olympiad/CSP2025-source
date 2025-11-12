#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
int n,q,ans;
string s1[1000010],s2[1000010],t1[1000010],t2[1000010],tt[1000010];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i =0;i < n;i++){
        cin>>s1[i]>>s2[i];
    }
    for(int i = 0;i < q;i++){
        cin>>t1[i]>>t2[i];
        tt[i] = t1[i];
    }
    for(int i = 0;i < q;i++){
        ans = 0;
        for(int j = 0;j < n;j++){
            if(t1[i].find(s1[j]) != -1){
                for(int k = tt[j].find(s1[j]);k <= tt[j].find(s1[j]) + s1[j].size();k++){
                    t1[i][k] = s2[j][k - tt[j].find(s1[j])];
                }
                if(t1[i].compare(t2[i]) == 0){
                    ans++;
                }
            }
            t1[i] = tt[i];
        }
    }
    cout<<ans;
}
