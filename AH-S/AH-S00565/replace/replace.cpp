#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<map>
#define ll long long
using namespace std;
int n,q;
string s1[200010],s2[200010];
string a,b;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
            cin>>s1[i]>>s2[i];
    }
    while(q--){
        int cnt=0;
        cin>>a>>b;
        for(int i=1;i<=n;i++){
            int k=a.find(s1[i]);
            if(k!=-1){
                    string w=a;
                string t=w.replace(k,s1[i].size(),s2[i]);
                if(t==b) cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
