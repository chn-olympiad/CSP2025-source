#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n,m,s[100005],c[100005],ans,d[10005],cnt,re;
bool ruler;
long long po;
string str;
int main(){
    cin>>n>>m>>str;
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
        s[i] = str[i-1]-'0';
    }
    for(int i=1;i<=10005;i++) d[i] = 1;
    for(int o=1;o<=n*n*n;o++){
        bool vis[10005] = {};
        cnt = 0;
        d[n]++;
        for(int i=n;i>1;i--){
            if(d[i]>n){
                d[i] = 1;
                d[i-1]++;
            }
        }
        for(int i=1;i<=n;i++){
            if(!vis[d[i]]){
                vis[d[i]]=1;
            }
            else{
                ruler = 1;
                break;
            }
        }
        if(ruler){
            ruler = 0;
            ///////////
            continue;
        }
        re = 0;
        for(int e=1;e<=n;e++){

            //ut<<d[e]<<' ';

            if(!s[d[e]]||re >= c[e]){
                re++;

                //ut<<re<<' '<<c[e]<<endl;

                continue;
            }
            cnt++;
            //ut<<endl;
        }

        //ut<<cnt<<endl<<endl;

        if(cnt >= m)ans++;
    }
    cout<<ans;
    return 0;
}
