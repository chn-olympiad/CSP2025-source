#include<bits/stdc++.h>
using namespace std;

pair<string,string> s[100010];
int dis[100010];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i = 0; i < n; i++){
        string x,y;
        cin>>x>>y;
        s[i].first = x;
        s[i].second = y;
        int pos = -1,cnt = 0,pos1 = -1;
        for(int j = 0; j < x.size(); j++){
            if(x[j] != y[j] && !cnt){
                pos = j;
                cnt++;
                continue;
            }
            if(x[j] != y[j]){
                pos1 = j;
            }
        }
        dis[i] = pos-pos1;
        if(pos1 = -1){
            dis[i] = -1;
        }
    }
    while(q--){
        string t1,t2,c;
        cin>>t1>>t2;
        int pos = -1,cnt = 0,pos1 = -1;
        for(int i = 0; i < t1.size(); i++){
            if(t1[i] != t2[i] && !cnt){
                pos = i;
                cnt++;
                continue;
            }
            if(t1[i] != t2[i]){
                pos1 = i;
            }
        }
        bool flag = 0;
        if(pos1 == -1){
            flag = 1;
        }
        int diss = pos-pos1,ans = 0;
        for(int i = 0; i < n; i++){
            if(flag){
                if(dis[i] == -1){
                    cout<<1<<endl;
                    return 0;
                }
            }
            else if(abs(dis[i]) == abs(diss)){
                ans++;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
