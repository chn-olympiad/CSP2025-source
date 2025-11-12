#include <bits/stdc++.h>
using namespace std;
int n,q,cnt=0;
char s[200005][2][5000005],t[2][5000005],tb[5000005];
int cha(int a,int b){
    for(int i = a;i < a+strlen(s[b][0]);i++){
        if(s[b][0][i-a]!=t[0][i]){
            return 0;
        }
        tb[i] = t[0][i];
        t[0][i] = s[b][1][i-a];
    }
    for(int i = 0;i < strlen(t[0]);i++){
        if(t[0][i]!=t[1][i]){
            for(int j = a;j < a+strlen(s[b][0]);j++){
                t[0][j] = tb[j];
            }
            return 0;
        }
    }
    for(int i = a;i < a+strlen(s[b][0]);i++){
        t[0][i] = tb[i];
    }
    return 1;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i = 0;i < n;i++){
        cin>>s[i][0]>>s[i][1];
    }
    for(int i = 0;i < q;i++){
        cin>>t[0]>>t[1];
        if(strlen(t[0])!=strlen(t[1])){
            cout<<0;
            for(int j = 0;j < strlen(t[0]);j++){
                t[0][j] = 0;
            }
            for(int j = 0;j < strlen(t[1]);j++){
                t[1][j] = 0;
            }
            continue;
        }
        for(int j = 0;j < n;j++){
            for(int k = 0;k+strlen(s[j][0]) <= strlen(t[0]);k++){
                if(cha(k,j)){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
        cnt = 0;
        for(int i = 0;i < strlen(t[0]);i++){
            t[0][i] = 0;
            t[1][i] = 0;
        }
    }
    return 0;
}
