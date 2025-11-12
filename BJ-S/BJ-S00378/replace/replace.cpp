#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,q,ans;
string s[N][3],qs1,qs2;
int check(string s1,string s2,int pos){
    if(s1.size()!=s2.size()) return 0;
    bool flag=false;
    for(int i = 0;i < s1.size();i++){
        cout<<s1[i]<<" "<<s2[i]<<" "<<s[pos][1][0]<<" "<<s[pos][2][0]<<" "<<s1.substr(i,s[pos][1].size())<<" "<<s2.substr(i,s[pos][2].size())<<endl;
        if(flag) return 0;
            if(s[pos][1][0]!=s1[i]||s[pos][2][0]!=s2[i]) return 0;
            if(s1.substr(i,s[pos][1].size())!=s[pos][1]||s2.substr(i,s[pos][2].size())!=s[pos][2]) return 0;
        flag=true;
    }
    return 1;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i = 1;i <= n;i++){
        cin>>s[i][1]>>s[i][2];
    }
    for(int i = 1;i <= q;i++){
        cin>>qs1>>qs2;
        if(qs1.size()!=qs2.size()){
            printf("0\n");
            continue;
        }
        for(int j = 1;j <= n;j++){
            ans+=check(qs1,qs2,j);
        }
        printf("%d\n",ans);
    }
    return 0;
}
