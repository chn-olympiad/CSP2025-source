#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n,q;
string str1[maxn],str2[maxn];
set<string> s1,s2;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>str1[i]>>str2[i];
        s1.insert(str1[i]);
        s2.insert(str2[i]);
    }
    while(q--){
        string q1,q2;
        cin>>q1>>q2;
        int cnt=0;
        if(s1.find(q1)!=s1.end()){
            cnt++;
        }
        if(s2.find(q2)!=s2.end()){
            cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
