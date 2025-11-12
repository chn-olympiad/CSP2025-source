#include<iostream>
#include<algorithm>
using namespace std;
string s[20005],s1[20005];
int cnt;
int n,m;
bool f(string a,string b,string s,string s1){
    a.replace(a.find(s),s.size(),s1);
    if(a==b){
        return 1;
    }
    return 0;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i]>>s1[i];
    }
    for(int i=1;i<=m;i++){
        string a,b;
        cin>>a>>b;
        for(int j=1;j<=n;j++){
            if(f(a,b,s[j],s1[j])){
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
