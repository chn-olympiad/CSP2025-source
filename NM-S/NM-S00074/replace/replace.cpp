#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,q,ans = 0;
int bn1,bn2;
string t1,t2;
string smp[200218][2];
int bmovep[200218][2];
void isexist(string s1,string s2){
    for(int i = 0,j;i<t1.size();++i){
        j = 0;
        while(i<t1.size()&&j<s1.size()&&t1[i] == s1[j]){++i,++j;}
        if(j == s1.size()){
            string to = t1.substr(0,i-j)+s2;
            if(i<t1.size())to+=t1.substr(i);
            if(to == t2)ans++;
        }
        i-=j;
    }
}
void isbmove(){
    for(int i = 1;i<=n;++i){
        if(bn1>=bmovep[i][0]&&t1.size()-bn1>=smp[i][0].size()-bmovep[i][0]){
            if(bn1-bn2 == bmovep[i][0]-bmovep[i][1]){
                ans++;
            }

        }
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    bool flag = true;
    for(int i = 1;i<=n;++i){
        cin>>smp[i][0]>>smp[i][1];
        for(int j = 0,sumb1 = 0,sumb2 = 0;j<smp[i][0].size();++j){
            if(smp[i][0][j] != 'a'&&smp[i][0][j]!= 'b')flag = false;
            if(smp[i][1][j] != 'a'&&smp[i][1][j]!= 'b')flag = false;
            sumb1+=smp[i][0][j] == 'b'?1:0;
            sumb2+=smp[i][1][j] == 'b'?1:0;
            if(sumb1>1||sumb2>1)flag = false;
        }
    }
    if(n*q<=100000000){
        while(q--){
            cin>>t1>>t2;
            if(t1.size()!=t2.size()){
                printf("0\n");
                continue;
            }
            for(int i = 1;i<=n;++i){
                isexist(smp[i][0],smp[i][1]);
            }
            printf("%d\n",ans);
            ans = 0;
        }
        return 0;
    }
    if(flag){
        for(int i = 1;i<=n;++i){
            for(int j = 0;j<=smp[i][0].size();++j){
                if(smp[i][0][j] == 'b')bmovep[i][0] = j;
                if(smp[i][1][j] == 'b')bmovep[i][1] = j;
            }
        }
        while(q--){
            cin>>t1>>t2;
            if(t1.size()!=t2.size()){
                printf("0\n");
                continue;
            }
            for(int i = 0;i<t1.size();++i){
                if(t1[i] == 'b')bn1 = i;
                if(t2[i] == 'b')bn2 = i;
            }
            isbmove();
            printf("%d\n",ans);
            ans = 0;
        }
    }
}
