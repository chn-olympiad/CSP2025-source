#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],used[505];
string s;
long long cnt = 0;
void getans(int level){
    if(level>n){
        int quits = 0;
        for(int i = 1;i<=n;i++){
            if(c[i] <= quits || s[i] == '1'){
                quits++;
            }
            else cnt++;
        }
    }
    int flag = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=level;j++){
            if(i == used[j]){
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            flag = 0;
            continue;
        }
        used[level] = i;
        getans(level+1);
        used[level] = 0;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i = 1;i<=n;i++){
        cin>>c[i];
    }
    getans(1);
    cout<<cnt;
    return 0;
}
